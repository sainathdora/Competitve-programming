ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int tt;
    cin>>tt;
    while (tt--)
    {
        int n;
        cin>>n;
        vi a(n);
        for(int i(0); i<n; ++i)cin>>a[i];
        solve(a);
    }