#pragma once

template<typename a_type> class Vector2
{
public:
	Vector2();
	Vector2(const a_type inputX, const a_type inputY);

	// Overloads
	bool operator==(const Vector2<a_type> &b);
	bool operator!=(const Vector2<a_type> &b);
	Vector2<a_type> operator+=(const Vector2<a_type> &b);
	Vector2<a_type> operator+(const Vector2<a_type> &b);
	Vector2<a_type> operator-=(const Vector2<a_type> &b);
	Vector2<a_type> operator-(const Vector2<a_type> &b);
	Vector2<a_type> operator*=(const Vector2<a_type> &b);
	Vector2<a_type> operator*=(const a_type &b);
	Vector2<a_type> operator*(const Vector2<a_type> &b);
	Vector2<a_type> operator*(const a_type &b);
	Vector2<a_type> operator/=(const Vector2<a_type> &b);
	Vector2<a_type> operator/(const Vector2<a_type> &b);

	a_type x;
	a_type y;
};

template<typename a_type>Vector2<a_type>::Vector2(){
	x = 0;
	y = 0;
}
template<typename a_type>Vector2<a_type>::Vector2(const a_type inputX, const a_type inputY){
	x = inputX;
	y = inputY;
}

// Overloads
template<typename a_type> bool Vector2<a_type>::operator==(const Vector2<a_type> &b){
	return (x == b.x && y == b.y);
}
template<typename a_type> bool Vector2<a_type>::operator!=(const Vector2<a_type> &b){
	return !(*this == b);
}
template<typename a_type> Vector2<a_type> Vector2<a_type>::operator+=(const Vector2<a_type> &b){
	x += b.x;
	y += b.y;
	return *this;
}
template<typename a_type> Vector2<a_type> Vector2<a_type>::operator+(const Vector2<a_type> &b){
	Vector2<a_type> temp = *this;
	temp += b;
	return temp;
}
template<typename a_type> Vector2<a_type> Vector2<a_type>::operator-=(const Vector2<a_type> &b){
	x -= b.x;
	y -= b.y;
	return *this;
}
template<typename a_type> Vector2<a_type> Vector2<a_type>::operator-(const Vector2<a_type> &b){
	Vector2<a_type> temp = *this;
	temp -= b;
	return temp;
}
template<typename a_type> Vector2<a_type> Vector2<a_type>::operator*=(const Vector2<a_type> &b){
	x *= b.x;
	y *= b.y;
	return *this;
}
template<typename a_type> Vector2<a_type> Vector2<a_type>::operator*=(const a_type &b){
	x *= b;
	y *= b;
	return *this;
}
template<typename a_type> Vector2<a_type> Vector2<a_type>::operator*(const Vector2<a_type> &b){
	Vector2<a_type> temp = *this;
	temp *= b;
	return temp;
}
template<typename a_type> Vector2<a_type> Vector2<a_type>::operator*(const a_type &b){
	Vector2<a_type> temp = *this;
	temp *= b;
	return temp;
}
template<typename a_type> Vector2<a_type> Vector2<a_type>::operator/=(const Vector2<a_type> &b){
	x /= b.x;
	y /= b.y;
	return *this;
}
template<typename a_type> Vector2<a_type> Vector2<a_type>::operator/(const Vector2<a_type> &b){
	Vector2<a_type> temp = *this;
	temp /= b;
	return temp;
}