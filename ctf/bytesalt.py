import Crypto.Util.number
a=0x7573625f7265736572766174696f6e5f64657369726564
print(Crypto.Util.number.long_to_bytes(a).decode())
