int main()
{
    int t,p,n,others,checkpoints,rem_elements,contr,pwr,ans;
    sscanf(Stdio.stdin->gets(),"%d",t);
    while(t--)
    {
        sscanf(Stdio.stdin->gets(),"%d %d",p,n);
        pwr = p;
        ans = 0;
        while(pwr <= n)
        {
            checkpoints = n/pwr;
            rem_elements = n%pwr;            
            contr = pwr * (checkpoints*(checkpoints-1)/2);
            others = checkpoints*(rem_elements+1);
            ans += (contr+others);
            pwr *= p;
        }
        write(ans+"\n");
    }
    return 0;
}
