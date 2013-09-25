class Vector
{
	public:
		unsigned int *array;
		int length;
		
		Vector (int size);
		unsigned int get (int index) const;
		Vector & operator=(const Vector & s);
		const unsigned int &operator[](const int & index) const;

	private:
		void fitArray (const Vector & vec);
};