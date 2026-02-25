int helper(long long n) {
    if (n < 10) return n;
    
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return helper(sum);
}

int superDigit(string n, int k) {
    long long initial_sum = 0;
    
    for (char c : n) {
        initial_sum += c - '0';
    }
    
    return helper(initial_sum * k);
}


// time complexity of helper = o(logn)
// time complexity of superDigit(n,k) = o(m)
// m is length of n
