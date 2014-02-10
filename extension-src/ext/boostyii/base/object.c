
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(boostyii_base_Object) {

	ZEPHIR_REGISTER_CLASS(boostyii\\base, Object, boostyii, base_object, boostyii_base_object_method_entry, 0);

	zend_class_implements(boostyii_base_object_ce TSRMLS_CC, 1, boostyii_base_arrayable_ce);

	return SUCCESS;

}

PHP_METHOD(boostyii_base_Object, className) {

	ZEPHIR_MM_GROW();

	zephir_call_func(return_value, "get_called_class");
	RETURN_MM();

}

PHP_METHOD(boostyii_base_Object, __construct) {

	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	}


	if (!ZEPHIR_IS_EMPTY(config)) {
		zephir_call_static_p2_noret("boostyii\\BoostYii", "configure", this_ptr, config);
	}
	zephir_call_method_noret(this_ptr, "init");
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(boostyii_base_Object, init) {



}

PHP_METHOD(boostyii_base_Object, hasProperty) {

	zend_bool checkVars, _1;
	zval *name_param = NULL, *checkVars_param = NULL, *_0, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &checkVars_param);

	if (Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(name_param) == IS_STRING) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!checkVars_param) {
		checkVars = 1;
	} else {
		if (Z_TYPE_P(checkVars_param) != IS_BOOL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'checkVars' must be a bool") TSRMLS_CC);
			RETURN_MM_NULL();
		}

		checkVars = Z_BVAL_P(checkVars_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p2(_0, this_ptr, "cangetproperty", name, (checkVars ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	_1 = zephir_is_true(_0);
	if (!(_1)) {
		ZEPHIR_INIT_VAR(_2);
		zephir_call_method_p2(_2, this_ptr, "cansetproperty", name, ZEPHIR_GLOBAL(global_false));
		_1 = zephir_is_true(_2);
	}
	RETURN_MM_BOOL(_1);

}

PHP_METHOD(boostyii_base_Object, canGetProperty) {

	zend_bool checkVars, _1, _2;
	zval *name_param = NULL, *checkVars_param = NULL, *_3;
	zval *name = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &checkVars_param);

	if (Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(name_param) == IS_STRING) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!checkVars_param) {
		checkVars = 1;
	} else {
		checkVars = zephir_get_boolval(checkVars_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "get", name);
	_1 = (zephir_method_exists(this_ptr, _0 TSRMLS_CC)  == SUCCESS);
	if (!(_1)) {
		_2 = checkVars;
		if (_2) {
			ZEPHIR_INIT_VAR(_3);
			zephir_call_func_p2(_3, "property_exists", this_ptr, name);
			_2 = zephir_is_true(_3);
		}
		_1 = _2;
	}
	RETURN_MM_BOOL(_1);

}

PHP_METHOD(boostyii_base_Object, canSetProperty) {

	zend_bool checkVars, _1, _2;
	zval *name_param = NULL, *checkVars_param = NULL, *_3;
	zval *name = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &checkVars_param);

	if (Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(name_param) == IS_STRING) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!checkVars_param) {
		checkVars = 1;
	} else {
		if (Z_TYPE_P(checkVars_param) != IS_BOOL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'checkVars' must be a bool") TSRMLS_CC);
			RETURN_MM_NULL();
		}

		checkVars = Z_BVAL_P(checkVars_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "set", name);
	_1 = (zephir_method_exists(this_ptr, _0 TSRMLS_CC)  == SUCCESS);
	if (!(_1)) {
		_2 = checkVars;
		if (_2) {
			ZEPHIR_INIT_VAR(_3);
			zephir_call_func_p2(_3, "property_exists", this_ptr, name);
			_2 = zephir_is_true(_3);
		}
		_1 = _2;
	}
	RETURN_MM_BOOL(_1);

}

PHP_METHOD(boostyii_base_Object, hasMethod) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


	RETURN_MM_BOOL((zephir_method_exists(this_ptr, name TSRMLS_CC)  == SUCCESS));

}

PHP_METHOD(boostyii_base_Object, toArray) {

	ZEPHIR_MM_GROW();

	zephir_call_static_p1(return_value, "boostyii\\BoostYii", "getobjectvars", this_ptr);
	RETURN_MM();

}

