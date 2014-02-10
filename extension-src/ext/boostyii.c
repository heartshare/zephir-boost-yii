
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "boostyii.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"

zend_class_entry *boostyii_base_arrayable_ce;
zend_class_entry *boostyii_base_object_ce;
zend_class_entry *boostyii_boostyii_ce;

ZEND_DECLARE_MODULE_GLOBALS(boostyii)

static PHP_MINIT_FUNCTION(boostyii)
{
#if PHP_VERSION_ID < 50500
	const char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		char *tmp = calloc(strlen(old_lc_all)+1, 1);
		memcpy(tmp, old_lc_all, strlen(old_lc_all));
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(boostyii_base_Arrayable);
	ZEPHIR_INIT(boostyii_BoostYii);
	ZEPHIR_INIT(boostyii_base_Object);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(boostyii)
{

	assert(ZEPHIR_GLOBAL(function_cache) == NULL);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_zephir_globals *zephir_globals TSRMLS_DC)
{

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache options */
	zephir_globals->function_cache = NULL;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(boostyii)
{

	php_zephir_init_globals(ZEPHIR_VGLOBAL TSRMLS_CC);
	//boostyii_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(boostyii)
{

	if (ZEPHIR_GLOBAL(start_memory) != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	if (ZEPHIR_GLOBAL(function_cache) != NULL) {
		zend_hash_destroy(ZEPHIR_GLOBAL(function_cache));
		FREE_HASHTABLE(ZEPHIR_GLOBAL(function_cache));
		ZEPHIR_GLOBAL(function_cache) = NULL;
	}

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(boostyii)
{
	php_info_print_table_start();
	php_info_print_table_header(2, PHP_BOOSTYII_NAME, "enabled");
	php_info_print_table_row(2, "Version", PHP_BOOSTYII_VERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(boostyii)
{
	zephir_memory_entry *start;

	php_zephir_init_globals(boostyii_globals TSRMLS_CC);

	/* Start Memory Frame */
	start = (zephir_memory_entry *) pecalloc(1, sizeof(zephir_memory_entry), 1);
	start->addresses       = pecalloc(16, sizeof(zval*), 1);
	start->capacity        = 16;
	start->hash_addresses  = pecalloc(4, sizeof(zval*), 1);
	start->hash_capacity   = 4;

	boostyii_globals->start_memory = start;

	/* Global Constants */
	ALLOC_PERMANENT_ZVAL(boostyii_globals->global_false);
	INIT_PZVAL(boostyii_globals->global_false);
	ZVAL_FALSE(boostyii_globals->global_false);
	Z_ADDREF_P(boostyii_globals->global_false);

	ALLOC_PERMANENT_ZVAL(boostyii_globals->global_true);
	INIT_PZVAL(boostyii_globals->global_true);
	ZVAL_TRUE(boostyii_globals->global_true);
	Z_ADDREF_P(boostyii_globals->global_true);

	ALLOC_PERMANENT_ZVAL(boostyii_globals->global_null);
	INIT_PZVAL(boostyii_globals->global_null);
	ZVAL_NULL(boostyii_globals->global_null);
	Z_ADDREF_P(boostyii_globals->global_null);

}

static PHP_GSHUTDOWN_FUNCTION(boostyii)
{
	assert(boostyii_globals->start_memory != NULL);

	pefree(boostyii_globals->start_memory->hash_addresses, 1);
	pefree(boostyii_globals->start_memory->addresses, 1);
	pefree(boostyii_globals->start_memory, 1);
	boostyii_globals->start_memory = NULL;
}

zend_module_entry boostyii_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_BOOSTYII_EXTNAME,
	NULL,
	PHP_MINIT(boostyii),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(boostyii),
#else
	NULL,
#endif
	PHP_RINIT(boostyii),
	PHP_RSHUTDOWN(boostyii),
	PHP_MINFO(boostyii),
	PHP_BOOSTYII_VERSION,
	ZEND_MODULE_GLOBALS(boostyii),
	PHP_GINIT(boostyii),
	PHP_GSHUTDOWN(boostyii),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_BOOSTYII
ZEND_GET_MODULE(boostyii)
#endif
