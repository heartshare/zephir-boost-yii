
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(boostyii_base_Arrayable) {

	ZEPHIR_REGISTER_INTERFACE(boostyii\\base, Arrayable, boostyii, base_arrayable, boostyii_base_arrayable_method_entry);


	return SUCCESS;

}

ZEPHIR_DOC_METHOD(boostyii_base_Arrayable, toArray);

