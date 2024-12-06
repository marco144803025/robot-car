void init(void), wait(unsigned), led(char);
short getX(void), getY(void), getV(void);
bool uart1_send(char), uart3_send(char);
bool uart1_send(const char* p, int n);
bool uart1_print(const char* p);
bool uart1_read(char &c);