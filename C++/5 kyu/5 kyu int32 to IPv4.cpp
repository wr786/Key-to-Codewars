std::string uint32_to_ip(uint32_t ip)
{
  std::string ret;
  for(size_t i=4; i; i--) {
    if(i != 4) ret = '.' + ret;
    ret = std::to_string((ip & ((1<<8) - 1))) + ret;
    ip >>= 8;
  }
  return ret;
}
