#ifndef EVAL_LAGRANGE_H_INCLUDED
#define EVAL_LAGRANGE_H_INCLUDED

#include <vector>
#include <iostream>
using namespace std;

#include <cmath>

template<typename TT>
TT eval_lagrange(TT x,vector<TT> &x_upts,int id)
{
    TT eval=1.0;

    TT x0=x_upts[id];

   for(int i=0; i!=(int)(x_upts.size()); ++i)
   {
	   if(i!=id)
		   eval *= (x-x_upts[i])/(x0-x_upts[i]);
   }

    return eval;
}

template<typename TT>
TT eval_d_lagrange(TT x,vector<TT> &x_upts,int id)
{
    TT eval0,eval1=0.0,eval2=1.0;
    TT x0=x_upts[id];
    int order = (int)(x_upts.size());

    for(int i=0; i!=order; ++i)
    {
        if(i!=id)
        {
            eval2 *= (x0-x_upts[i]);
            TT eval3 = 1.0;
            for(int j=0; j!=order; ++j)
            {
                if(j!=i&&j!=id)
                {
                    eval3 *= (x-x_upts[j]);
                }
            }
            eval1 += eval3;
        }
    }

    eval0 = eval1/eval2;

    return eval0;
}

template<typename TT>
TT eval_legendre(TT x,int id)
{
    if(id==0)
        return 1.0;
    else if(id==1)
        return x;
    else if(id==2)
        return 1.5*x*x-0.5;
    else if(id==3)
        return 2.5*pow(x,3)-1.5*x;
    else if(id==4)
        return 4.375*pow(x,4)-3.75*x*x+0.375;
    else if(id==5)
        return 7.875*pow(x,5)-8.75*pow(x,3)+1.875*x;
    else
	{
		cout<<" not support fucnction called !!! ";
        return -9999.0;
	}
}

template<typename TT>
TT eval_d_legendre(TT x,int id)
{

    if(id==0)
        return 0.0;
    else if(id==1)
        return 1.0;
    else if(id==2)
        return 3.0*x;
    else if(id==3)
        return 7.5*x*x-1.5;
    else if(id==4)
        return 17.5*pow(x,3)-7.5*x;
    else if(id==5)
        return 39.375*pow(x,4)-26.25*x*x+1.875;
    else
	{
		cout<<" not support fucnction called !!! ";
        return -9999.0;
	}
}

template<typename TT>
TT eval_lobatto(TT x,int id)
{
    if(id==2)
        return 1.5*x*x-1.5;
    else if(id==3)
        return 2.5*pow(x,3)-2.5*x;
    else if(id==4)
        return 4.375*pow(x,4)-5.25*x*x+0.875;
    else if(id==5)
        return 7.875*pow(x,5)-11.25*pow(x,3)+3.375*x;
    else
	{
		cout<<" not support fucnction called !!! ";
        return -9999.0;
	}
}

template<typename TT>
TT eval_d_lobatto(TT x,int id)
{

    if(id==2)
        return 3.0*x;
    else if(id==3)
        return 7.5*x*x-2.5;
    else if(id==4)
        return 17.5*pow(x,3)-10.5*x;
    else if(id==5)
        return 39.375*pow(x,4)-33.75*x*x+3.375;
    else
	{
		cout<<" not support fucnction called !!! ";
        return -9999.0;
	}
}

#endif // EVAL_LAGRANGE_H_INCLUDED
