
extern zend_class_entry *boostyii_base_object_ce;

ZEPHIR_INIT_CLASS(boostyii_base_Object);

PHP_METHOD(boostyii_base_Object, className);
PHP_METHOD(boostyii_base_Object, __construct);
PHP_METHOD(boostyii_base_Object, init);
PHP_METHOD(boostyii_base_Object, hasProperty);
PHP_METHOD(boostyii_base_Object, canGetProperty);
PHP_METHOD(boostyii_base_Object, canSetProperty);
PHP_METHOD(boostyii_base_Object, hasMethod);
PHP_METHOD(boostyii_base_Object, toArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_boostyii_base_object___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_boostyii_base_object_hasproperty, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, checkVars)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_boostyii_base_object_cangetproperty, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, checkVars)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_boostyii_base_object_cansetproperty, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, checkVars)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_boostyii_base_object_hasmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(boostyii_base_object_method_entry) {
	PHP_ME(boostyii_base_Object, className, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(boostyii_base_Object, __construct, arginfo_boostyii_base_object___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(boostyii_base_Object, init, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(boostyii_base_Object, hasProperty, arginfo_boostyii_base_object_hasproperty, ZEND_ACC_PUBLIC)
	PHP_ME(boostyii_base_Object, canGetProperty, arginfo_boostyii_base_object_cangetproperty, ZEND_ACC_PUBLIC)
	PHP_ME(boostyii_base_Object, canSetProperty, arginfo_boostyii_base_object_cansetproperty, ZEND_ACC_PUBLIC)
	PHP_ME(boostyii_base_Object, hasMethod, arginfo_boostyii_base_object_hasmethod, ZEND_ACC_PUBLIC)
	PHP_ME(boostyii_base_Object, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
