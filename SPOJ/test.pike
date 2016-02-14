int main()
{
    array(int) a = ({5,2,6});
    sort(a);
    a = reverse(a);
    for(int i=0;i<sizeof(a);i++)
        write("%d\n",a[i]);
    return 0;
}

