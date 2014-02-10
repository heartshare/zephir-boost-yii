
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(boostyii_BoostYii) {

	ZEPHIR_REGISTER_CLASS(boostyii, BoostYii, boostyii, boostyii, boostyii_boostyii_method_entry, 0);


	return SUCCESS;

}

/**
 * @see BaseYii::getObjectVars()
 */
PHP_METHOD(boostyii_BoostYii, getObjectVars) {

	zval *obj;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);



	zephir_call_func_p1(return_value, "get_object_vars", obj);
	RETURN_MM();

}

/**
 * @see BaseYii::configure()
 */
PHP_METHOD(boostyii_BoostYii, configure) {

	HashTable *_1;
	HashPosition _0;
	zval *obj, *properties, *name = NULL, *value = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &obj, &properties);

	ZEPHIR_SEPARATE_PARAM(obj);


	zephir_is_iterable(properties, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		zephir_update_property_zval_zval(obj, name, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

