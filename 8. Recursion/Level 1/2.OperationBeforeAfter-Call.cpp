// Print numbers till 'n' 

// decreasing order
void dec(int n) {
    if (n == 0)
        return;
    cout << n << " ";
    dec(n - 1);
}

// increasing order
void inc(int n) {
    if (n == 0)
        return;
    inc(n - 1);
    cout << n << " ";
}