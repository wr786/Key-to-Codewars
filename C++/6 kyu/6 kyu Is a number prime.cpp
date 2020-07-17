bool isPrime(int num) {
  if(num <= 1) return false;
  for(size_t i = 2; i <= sqrt(num); i++)
    if (num % i == 0) return false;
  return true;
}