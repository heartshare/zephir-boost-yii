
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_BOOSTYII_H
#define PHP_BOOSTYII_H 1

#include "kernel/globals.h"

#define PHP_BOOSTYII_NAME    "boostyii"
#define PHP_BOOSTYII_VERSION "0.0.1"
#define PHP_BOOSTYII_EXTNAME "boostyii"



ZEND_BEGIN_MODULE_GLOBALS(boostyii)

	/* Memory */
	zephir_memory_entry *start_memory;
	zephir_memory_entry *active_memory;

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/* Function cache */
	HashTable *function_cache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(boostyii)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(boostyii)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(boostyii_globals_id, zend_boostyii_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (boostyii_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_boostyii_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(boostyii_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(boostyii_globals)
#endif

#define zephir_globals boostyii_globals
#define zend_zephir_globals zend_boostyii_globals

extern zend_module_entry boostyii_module_entry;
#define phpext_boostyii_ptr &boostyii_module_entry

#endif
