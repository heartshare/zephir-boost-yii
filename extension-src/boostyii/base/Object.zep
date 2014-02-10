namespace boostyii\base;

class Object implements Arrayable {
	public static function className()
	{
		return get_called_class();
	}

	public function __construct(config=[])
	{
		if(!empty(config)) {
			boostyii\BoostYii::configure(this, config);
		}
		this->init();
	}

	public function init()
	{
	}

	public function hasProperty(string! name,boolean! checkVars = true) -> boolean
	{
		return this->canGetProperty(name, checkVars) || this->canSetProperty(name, false);
	}


	public function canGetProperty(string! name,boolean checkVars = true) -> boolean
	{
		return method_exists(this, "get" . name) || checkVars && property_exists(this, name);
	}

	public function canSetProperty(string! name, boolean! checkVars = true) -> boolean
	{
		return method_exists(this, "set" . $name) || checkVars && property_exists(this, name);
	}

	public function hasMethod(string name) -> boolean
	{
		return method_exists(this, name);
	}

	public function toArray() -> array
	{
		return boostyii\BoostYii::getObjectVars(this);
	}
}