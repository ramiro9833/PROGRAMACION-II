#include <iostream>
void d()
{ // aqu�
}

void c()
{
}

void b()
{
		c();
		d();
}

void a()
{
		b();
}

int main()
{
		a();
		
		return 0;
}
