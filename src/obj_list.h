#ifndef OBJ_LIST_H
#define OBJ_LIST_H

#include<vector>
#include<memory>
#include "object.h"

using std::make_shared;
using std::shared_ptr;

class obj_list :public object
{
public:
	std::vector<shared_ptr<object>> objects;

public:
	obj_list() {}
	obj_list(shared_ptr<object> obj) { add(obj); }

	void add(shared_ptr<object> obj)
	{
		objects.push_back(obj);
	}
	void clear()
	{
		objects.clear();
	}

	virtual bool on_hit(float tmin, float tmax, const ray& r, hit_values& hit_val) const override;
};

bool obj_list::on_hit(float tmin, float tmax, const ray& r, hit_values& hit_val) const
{
	bool got_hit=false;//If it hits atleast one object, this will be set true
	hit_values temp;
	float nearest_t = tmax;

	for (const shared_ptr<object>& obj : objects)
	{
		if (obj->on_hit(tmin, nearest_t, r, temp))
		{
			got_hit = true;
			nearest_t = temp.t;
			hit_val = temp;
		}
		
	}

	return got_hit;
}

#endif // !OBJ_LIST_H
