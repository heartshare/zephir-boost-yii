
extern zend_class_entry *boostyii_boostyii_ce;

ZEPHIR_INIT_CLASS(boostyii_BoostYii);

PHP_METHOD(boostyii_BoostYii, getObjectVars);
PHP_METHOD(boostyii_BoostYii, configure);

ZEND_BEGIN_ARG_INFO_EX(arginfo_boostyii_boostyii_getobjectvars, 0, 0, 1)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_boostyii_boostyii_configure, 0, 0, 2)
	ZEND_ARG_INFO(0, obj)
	ZEND_ARG_INFO(0, properties)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(boostyii_boostyii_method_entry) {
	PHP_ME(boostyii_BoostYii, getObjectVars, arginfo_boostyii_boostyii_getobjectvars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(boostyii_BoostYii, configure, arginfo_boostyii_boostyii_configure, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
