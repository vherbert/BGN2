template<typename T>
void BitEvalL1<T>::print() const
{
//	cout << "____________" << endl;
	zout(bit_masque);
	JUMP;
	bipoint.print();
//	cout << "____________" << endl;
}

template<typename T>
void BitEvalL1<T>::print_bit_masque() const
{
	zout(bit_masque);
}

template<typename T>
Bipoint<T> BitEvalL1<T>::get_bipoint() const
{
		return bipoint;
}


template<typename T>
BitEvalL1<T>::BitEvalL1(F2 a,Bipoint<T> b)
{
	bit_masque = a;
	bipoint = b;
}

template<typename T>
void BitEvalL1<T>::set_bit_masque(F2 bit)
//manipulateur pour modifer attribut si nécessaire, méthode définie en dehors de la classe
{
	bit_masque = bit;
}

template<typename T>
F2 BitEvalL1<T>::get_bit_masque() const
{
	return bit_masque;
}

template<typename T>
void BitEvalL1<T>::set_bipoint(Bipoint<T> b)
{
	bipoint = b;
}

template<typename T>
void BitEvalL1<T>::makeaffine()
{
	bipoint.makeaffine();
}
