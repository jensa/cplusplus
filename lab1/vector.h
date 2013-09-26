
class Vector
{
	int length;
	unsigned int *array;
	bool arrayCreated;

	public:
		Vector (int size);
		Vector (const Vector & vec);
		~Vector ();
		int getLength() const;
		void print();
		unsigned int get (int index) const;
		Vector & operator=(const Vector & s);
		Vector & operator=(const std::initializer_list<int>& il);
		unsigned int &operator[](const int & index) const;

	private:
		void fitArray (const Vector & vec);
};