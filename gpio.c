#include <ruby.h>
#include <stdio.h>
#include <bcm2835.h>
#include <pins.h>

VALUE rb_mRubyPi;

VALUE rb_cGPIO;

VALUE initialize(VALUE self) {
  if (!bcm2835_init())
    return 1;

  mapPins();

  printf("%s\n", "GPIO Initailized");

  int i;
  for (i=0; i<41;i++) {
    printf("pins[%d] = %d\n", i, pins[i]);
  }

  return Qtrue;
}

VALUE setPin(VALUE object, VALUE pin, VALUE on) {
  Check_Type(pin, T_FIXNUM);
  if (TYPE(on) != T_TRUE && TYPE(on) != T_FALSE)
    rb_raise(rb_eTypeError, "Second argument must be boolean");

  // converts pin into a uint8_t.
  uint8_t pinInt = FIX2INT(pin);

  bcm2835_gpio_fsel(pinInt, BCM2835_GPIO_FSEL_OUTP);

  if (on == Qtrue) {
    printf("Setting output of GPIO%u to high\n", pinInt);
    bcm2835_gpio_set(pinInt);
  } else if (on == Qfalse) {
    printf("Setting output of GPIO%u to low\n", pinInt);
    bcm2835_gpio_clr(pinInt);
  }

  return Qtrue;
}

VALUE pin(VALUE object, VALUE pin) {
  uint8_t pinInt = FIX2INT(pin);
  bcm2835_gpio_fsel(pinInt, BCM2835_GPIO_FSEL_INPT);
  if (bcm2835_gpio_lev(pinInt)) {
    printf("GPIO%u is high\n", pinInt);
    return Qtrue;
  } else {
    printf("GPIO%u is low\n", pinInt);
    return Qfalse;
  }
}

VALUE closeConnection(VALUE object) {
  bcm2835_close();

  return Qtrue;
}

void Init_gpio() {
  rb_mRubyPi = rb_define_module("RubyPi");
  rb_cGPIO = rb_define_class_under(rb_mRubyPi, "GPIO", rb_cObject);
  rb_define_method(rb_cGPIO, "initialize", initialize, 0);
  rb_define_method(rb_cGPIO, "setPin", setPin, 2);
  rb_define_method(rb_cGPIO, "pin", pin, 1);
  rb_define_method(rb_cGPIO, "close", closeConnection, 0);
}
