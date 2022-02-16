#pragma once
class view{
	public: 
		static view* get(char const* type);
	private:
		static view* obj;
};