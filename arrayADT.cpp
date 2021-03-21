#include<iostream>
using namespace std;

class array
{
    private:
        int *a;
        int size;
        int length;
    public:
        array(int n);
        int get_size();
        int get_len();
        void display();
        void add(int x);
        void insert(int i,int x);
        void del(int i);
        int get(int i);
        int max();
        int min();
        int sum();
        int avg();
        void reverse();
        void Lshift();
        void Rshift();
        void Lrotate();
        void Rrotate();
        void sort();
        bool isSorted();
        void insert_in_sort(int x);
        void arrange();//-ve(leftSide), +ve(rightSide)
        friend void merge(array &a1, array &a2, array &a3); //merge a1 & a2 into a3
        void set_unique();
        friend void uni_on(array &a1, array &a2, array &a3); //union a1 & a2 into a3
        friend void intersecti_on(array &a1, array &a2, array &a3); //intersect a1 & a2 into a3
        friend void difference(array &a1, array &a2, array &a3); //a3=a1-a2
        ~array();
};

array::array(int n)
{
    length=0;
    size=n;
    a=new int[size];
}
int array::get_size()
{
    return size;
}
int array::get_len()
{
    return length;
}
void array::display()
{
    for(int i=0;i<length;i++)
        cout<<a[i]<<" ";
}
void array::add(int x)
{
    if(length<size)
    {
        a[length]=x;
        length++;
    }
    else
        cout<<"Array is full";
}
void array::insert(int i,int x)
{
    if(length<size)
    {
        if(i>0 && i<=length)
        {
            i--;
            int n=length-1;
            while(n>=i)
            {
                a[n+1]=a[n];
                n--;
            }
            a[i]=x;
            length++;
        }
        else
            cout<<"Invalid index"<<endl;
    }
    else
        cout<<"Array is full"<<endl;
}
void array::del(int i)
{
    if(i>0 && i<=length)
    {
        i--;
        int n=length-1;
        while(i<=n)
        {
            a[i]=a[i+1];
            i++;
        }
        length--;
    }
    else
        cout<<"Invalid index"<<endl;
}
int array::get(int i)
{
    if(i>0 && i<=length)
        return a[--i];
    else
    {
        cout<<"Invalid index"<<endl;
        return -1;
    }
}
int array::max()
{
    if(length>0)
    {
        int max=a[0];
        for(int i=0;i<length;i++)
        {
            if(max<a[i])
                max=a[i];
        }
        return max;
    }
    else
    {
        cout<<"Array is empty"<<endl;
        return -1;
    }
}
int array::min()
{
    if(length>0)
    {
        int min=a[0];
        for(int i=0;i<length;i++)
        {
            if(min>a[i])
                min=a[i];
        }
        return min;
    }
    else
    {
        cout<<"Array is empty"<<endl;
        return -1;
    }
}
int array::sum()
{
    if(length>0)
    {
        int sum=0;
        for(int i=0;i<length;i++)
            sum+=a[i];
        return sum;
    }
    else
    {
        cout<<"Array is empty"<<endl;
        return -1;
    }
}
int array::avg()
{
    if(length>0)
    {
        int sum=array::sum();
        return sum/length;
    }
    else
    {
        cout<<"Array is empty"<<endl;
        return -1;
    }
}
void array::reverse()
{
    if(length>0)
    {
        int i=0;
        int l=length-1;
        int t;
        while(i<l)
        {
            t=a[i];
            a[i]=a[l];
            a[l]=t;
            i++;
            l--;
        }
    }
    else
        cout<<"Array is empty"<<endl;
}
void array::Lshift()
{
    if(length>0)
    {
        for(int i=0;i<length-1;i++)
            a[i]=a[i+1];
        a[length-1]=0;
    }
    else
        cout<<"Array is empty"<<endl;
}
void array::Rshift()
{
    if(length>0)
    {
        for(int n=length-1;n>0;n--)
            a[n]=a[n-1];
        a[0]=0;
    }
    else
        cout<<"Array is empty"<<endl;
}
void array::Lrotate()
{
    if(length>0)
    {
        int temp=a[0];
        for(int i=0;i<length-1;i++)
            a[i]=a[i+1];
        a[length-1]=temp;
    }
    else
        cout<<"Array is empty"<<endl;
}
void array::Rrotate()
{
    if(length>0)
    {
        int temp=a[length-1];
        for(int n=length-1;n>0;n--)
            a[n]=a[n-1];
        a[0]=temp;
    }
    else
        cout<<"Array is empty"<<endl;
}
void array::sort()
{
    if(length>0)
    {
        int temp;
        for(int i=0;i<length-1;i++)
        {
            for(int j=0;j<length-1-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    }
    else
        cout<<"Array is empty"<<endl;
}
bool array::isSorted()
{
    for(int i=0;i<length-1;i++)
    {
        if(a[i]>a[i+1])
            return false;
    }
    return true;
}
void array::insert_in_sort(int x)
{
    if(length==0)
    {
        a[length]=x;
        length++;
    }
    else if(length<size)
    {
        int i;
        for(i=length-1;x<a[i];i--)
        {
            a[i+1]=a[i];
        }
        a[i+1]=x;
        length++;
    }
    else
        cout<<"Array is full"<<endl;
}
void array::arrange()
{
    if(length>0)
    {
        int i=0,j=length-1,temp;
        while(i<j)
        {
            while(a[i]<0)
                i++;
            while(a[j]>=0)
                j--;
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }        
        }
    }
    else
        cout<<"Array is empty"<<endl;
}
void merge(array &a1,array &a2,array &c)
{
    int i=0,j=0;
    while((i<a1.length) && (j<a2.length))
    {
        if(a1.get(i+1) < a2.get(j+1))
        {
            c.add(a1.get(i+1));
            i++;
        }
        else
        {
            c.add(a2.get(j+1));
            j++;
        }
    }
    for(;i<a1.length;i++)
        c.add(a1.get(i+1));
    for(;j<a2.length;j++)
        c.add(a2.get(j+1));
}
void array::set_unique()
{
    bool change=0;
    for(int k=0;k<(length+1);k++)
    {
        change=0;
        for(int i=0;i<length-1;i++)
            for(int j=i+1;j<length;j++)
            {
                if(a[i]==a[j])
                {
                    int n=length-1;
                    while(j<=n)
                    {
                        a[j]=a[j+1];
                        j++;
                    }
                    length--;
                    change=1;
                }
            }
        if(change==0)
            break;
    }
}
void uni_on(array &a1,array &a2,array &c)
{
    for(int i=0;i<a1.get_len();i++)
        c.add(a1.get(i+1));
    for(int j=0;j<a2.get_len();j++)
    {
        bool present=0;
        for(int k=0;k<a1.get_len();k++)
        {
            if(a2.get(j+1)==a1.get(k+1))
            {
                present=1;
                break;
            }
        }
        if(present==0)
            c.add(a2.get(j+1));
    }
}
void intersecti_on(array &a1, array &a2, array &c)
{
    for(int i=0;i<a1.get_len();i++)
        for(int j=0;j<a2.get_len();j++)
            if(a1.get(i+1)==a2.get(j+1))
                c.add(a1.get(i+1));
}
void difference(array &a1, array &a2, array &c)
{
    for(int i=0;i<a1.get_len();i++)
    {
        bool present=0;
        for(int j=0;j<a2.get_len();j++)
            if(a1.get(i+1)==a2.get(j+1))
            {
                present=1;
                break;
            }
        if(present==0)
            c.add(a1.get(i+1));
    }
}
array::~array()
{
    delete []a;
}

void array_fun()
{
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    array a(n);
    while(1)
    {
        cout<<endl;
        int ch;
        cout<<"(1)Tell me the size of the array"<<endl;
        cout<<"(2)Tell me the length of the array"<<endl;
        cout<<"(3)Display the array"<<endl;
        cout<<"(4)Add new element"<<endl;
        cout<<"(5)Insert an element in a particular position"<<endl;
        cout<<"(6)Delete from a particular position"<<endl;
        cout<<"(7)Search a particular index"<<endl;
        cout<<"(8)Maximum number"<<endl;
        cout<<"(9)Minimum number"<<endl;
        cout<<"(10)Total summation"<<endl;
        cout<<"(11)Find average"<<endl;
        cout<<"(12)Reverse the array"<<endl;
        cout<<"(13)Left shift the array"<<endl;
        cout<<"(14)Right shift the array"<<endl;
        cout<<"(15)Left rotate the array"<<endl;
        cout<<"(16)Right rotate the array"<<endl;
        cout<<"(17)Sort the array"<<endl;
        cout<<"(18)Let's know if the array is sorted or not"<<endl;
        cout<<"(19)Insert an element inside a sorted array"<<endl;
        cout<<"(20)Arrange the array base on positive & negative elements"<<endl;
        cout<<"(21)Convert the array into a set"<<endl;
        cout<<"(22)Return to main menu"<<endl;
        cout<<"Your choice..."<<endl<<"\t\t";\
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Size-> "<<a.get_size()<<endl;
            break;
        case 2:
            cout<<"Length-> "<<a.get_len()<<endl;
            break;
        case 3:
            {
                a.display();
                cout<<endl;
            }
            break;
        case 4:
            {
                int x;
                cout<<"Enter the element: ";
                cin>>x;
                a.add(x);
            }
            break;
        case 5:
            {
                int y,x;
                cout<<"Enter the position: ";
                cin>>y;
                cout<<"Enter the element: ";
                cin>>x;
                a.insert(y,x);
            }
            break;
        case 6:
            {
                int y;
                cout<<"Enter the position: ";
                cin>>y;
                a.del(y);
            }
            break;
        case 7:
            {
                int y;
                cout<<"Enter the position: ";
                cin>>y;
                cout<<y<<"th Element-> "<<a.get(y);
            }
            break;
        case 8:
            cout<<"Max value-> "<<a.max()<<endl;
            break;
        case 9:
            cout<<"Min value-> "<<a.min()<<endl;
            break;
        case 10:
            cout<<"Sum-> "<<a.sum()<<endl;
            break;
        case 11:
            cout<<"Avg-> "<<a.avg()<<endl;
            break;
        case 12:
            a.reverse();
            break;
        case 13:
            a.Lshift();
            break;
        case 14:
            a.Rshift();
            break;
        case 15:
            a.Lrotate();
            break;
        case 16:
            a.Rrotate();
            break;
        case 17:
            a.sort();
            break;
        case 18:
            if(a.isSorted())
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            break;
        case 19:
        {
            int x;
            cout<<"Enter the element: ";
            cin>>x;
            a.insert_in_sort(x);
        }
            break;
        case 20:
            a.arrange();
            break;
        case 21:
            a.set_unique();
            break;
        case 22:
            return;
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
}

int main()
{
    cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*****************Array*****************~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    while(1)
    {
        cout<<endl;
        int ch;
        cout<<"(1)Creat an array"<<endl;
        cout<<"(2)Merge 2 arrays"<<endl;
        cout<<"(3)Union of 2 sets"<<endl;
        cout<<"(4)Intersection of 2 sets"<<endl;
        cout<<"(5)Difference of 2 sets"<<endl;
        cout<<"(6)Exit"<<endl;
        cout<<"Your choice..."<<endl<<"\t\t";\
        cin>>ch;
        switch (ch)
        {
        case 1:
        {
            array_fun();
        }
            break;
        case 2:
        {
            int n,m,temp;
            cout<<"Enter the size of the 1st array: ";
            cin>>n;
            cout<<"Enter the size of the 2nd array: ";
            cin>>m;
            array a(n);
            array b(m);
            array c(n+m);
            cout<<"\nNow enter the elements of the 1st array"<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<"Enter the "<<i+1<<"th element: ";
                cin>>temp;
                a.add(temp);
            }
            cout<<"\nNow enter the elements of the 2nd array"<<endl;
            for(int i=0;i<m;i++)
            {
                cout<<"Enter the "<<i+1<<"th element: ";
                cin>>temp;
                b.add(temp);
            }
            a.sort();
            b.sort();
            merge(a,b,c);
            cout<<"First array-> ";
            a.display();
            cout<<endl;
            cout<<"Second array-> ";
            b.display();
            cout<<endl;
            cout<<"Merged array-> ";
            c.display();
            cout<<endl;
        }
            break;
        case 3:
        {
            int n,m,temp;
            cout<<"Enter the size of the 1st set: ";
            cin>>n;
            cout<<"Enter the size of the 2nd set: ";
            cin>>m;
            array a(n);
            array b(m);
            array c(n+m);
            cout<<"\nNow enter the elements of the 1st set"<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<"Enter the "<<i+1<<"th element: ";
                cin>>temp;
                a.add(temp);
            }
            cout<<"\nNow enter the elements of the 2nd set"<<endl;
            for(int i=0;i<m;i++)
            {
                cout<<"Enter the "<<i+1<<"th element: ";
                cin>>temp;
                b.add(temp);
            }
            a.set_unique();
            b.set_unique();
            uni_on(a,b,c);
            cout<<"First set-> ";
            a.display();
            cout<<endl;
            cout<<"Second set-> ";
            b.display();
            cout<<endl;
            cout<<"Union set-> ";
            c.display();
            cout<<endl;
        }
            break;
        case 4:
        {
            int n,m,temp;
            cout<<"Enter the size of the 1st set: ";
            cin>>n;
            cout<<"Enter the size of the 2nd set: ";
            cin>>m;
            array a(n);
            array b(m);
            array c(n+m);
            cout<<"\nNow enter the elements of the 1st set"<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<"Enter the "<<i+1<<"th element: ";
                cin>>temp;
                a.add(temp);
            }
            cout<<"\nNow enter the elements of the 2nd set"<<endl;
            for(int i=0;i<m;i++)
            {
                cout<<"Enter the "<<i+1<<"th element: ";
                cin>>temp;
                b.add(temp);
            }
            a.set_unique();
            b.set_unique();
            intersecti_on(a,b,c);
            cout<<"First set-> ";
            a.display();
            cout<<endl;
            cout<<"Second set-> ";
            b.display();
            cout<<endl;
            cout<<"Intersection set-> ";
            c.display();
            cout<<endl;
        }
            break;
        case 5:
        {
            int n,m,temp;
            cout<<"Enter the size of the 1st set: ";
            cin>>n;
            cout<<"Enter the size of the 2nd set: ";
            cin>>m;
            array a(n);
            array b(m);
            array c(n+m);
            cout<<"\nNow enter the elements of the 1st set"<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<"Enter the "<<i+1<<"th element: ";
                cin>>temp;
                a.add(temp);
            }
            cout<<"\nNow enter the elements of the 2nd set"<<endl;
            for(int i=0;i<m;i++)
            {
                cout<<"Enter the "<<i+1<<"th element: ";
                cin>>temp;
                b.add(temp);
            }
            a.set_unique();
            b.set_unique();
            difference(a,b,c);
            cout<<"First set-> ";
            a.display();
            cout<<endl;
            cout<<"Second set-> ";
            b.display();
            cout<<endl;
            cout<<"(1st-2nd) set-> ";
            c.display();
            cout<<endl;
        }
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
    
    return 0;
}