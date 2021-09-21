import cryptography.x509
a=cryptography.x509.load_pem_x509_certificate(open("a.pem","rb").read())
print(cryptography.x509.load_der_x509_certificate(a))