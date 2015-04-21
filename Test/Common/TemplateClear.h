#ifndef __TEMPLATECLEAR_H__
#define __TEMPLATECLEAR_H__

template<typename T>
void ClearVecPtr( T &t )
{
	for ( typename T::iterator it = t.begin();
		it != t.end(); it++ )
	{
		delete (*it);
	}
	t.clear();
}

template<typename T>
void ClearMapPtr( T &t )
{
	for ( typename T::iterator it = t.begin();
		it != t.end(); it++ )
	{
		delete (it->second);
	}
	t.clear();
}

#endif // __TEMPLATECLEAR_H__