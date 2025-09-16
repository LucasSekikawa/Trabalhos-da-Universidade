int divRec(int dividendo, int divisor, int *resto) {
    if (dividendo < divisor) {
        *resto = dividendo; 
        return 0;           
    }
    return 1 + divRec(dividendo - divisor, divisor, resto);
}
