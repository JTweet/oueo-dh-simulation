# Diffie-Hellman Implementation for LIC25_PCOM7E April 2026 A, Unit 3

This implementation for the Diffie-Hellman algorithm was done for my studies at the University of Essex Online. It is *not* ready for production and must not be used in real-world applications relying on secure keys.

## Dependencies

The following external dependencies must be provided at a certain path from the project root:

| Dependency | Used Version | Path | Vendor Website |
|------------|--------------|------|----------------|
| GNU Multiple Precision Arithmetic Library (GMP) | v6.3.0 | ./gmp | https://gmplib.org/ |
| Libsodium | v1.0.21 | ./libsodium | https://libsodium.gitbook.io/ |

## Building and Testing

After placing the dependencies in the correct path, the project can be built and executed using the following commands from the project root. cmake v4.3.2 was used, other versions are untested.

```bash
cmake .
make
echo "bitlength,duration_s,exchange_success" >> dh-timing.sh
./gather-timing.sh
# The following commands are required to preprocess the data for inclusion in the candlestick-diagram
python3 -m venv .venv
source .venv/bin/activate
python3 -m pip install -r requirements.txt
python3 process-timing.py
```

