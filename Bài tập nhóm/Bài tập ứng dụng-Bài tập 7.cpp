#include<iostream>
using namespace std;
void nhap(int a[], int &n)
{
    cout<<"Nhap so luong phan tu :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"nhap phan tu a["<<i<<"]";
        cin>>a[i];
    }
}
void xuat(int a[],int n)
{
    cout<<"Mang vua nhap la :";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
void SapXep(int a[],int n)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            swap(a[i],a[j]);
            j++;
        }
    }
}
int main()
{
    int a[100];
    int n;
    nhap(a,n);
    xuat(a,n);
    SapXep(a,n);
    xuat(a,n);
    return 0;
}