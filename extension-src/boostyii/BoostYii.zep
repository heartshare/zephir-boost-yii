namespace boostyii;

class BoostYii
{
	/**
	 * @see BaseYii::getObjectVars()
	 */
	public static function getObjectVars(obj)
	{
		return get_object_vars(obj);
	}

	/**
	 * @see BaseYii::configure()
	 */
	public static function configure(obj,properties) -> void
	{
		var name,value;
		for name, value in properties {
			let obj->{name} = value;
		}
	}
}