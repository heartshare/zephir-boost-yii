
extern zend_class_entry *boostyii_base_arrayable_ce;

ZEPHIR_INIT_CLASS(boostyii_base_Arrayable);

ZEPHIR_INIT_FUNCS(boostyii_base_arrayable_method_entry) {
	PHP_ABSTRACT_ME(boostyii_base_Arrayable, toArray, NULL)
	PHP_FE_END
};
