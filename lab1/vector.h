class Vector
{
	int length;
	unsigned int *array;
	public:
		Vector (int size);
		Vector (const Vector & vec);
		int getLength() const;
		unsigned int get (int index) const;
		Vector & operator=(const Vector & s);
		unsigned int &operator[](const int & index) const;

	private:
		void fitArray (const Vector & vec);
};