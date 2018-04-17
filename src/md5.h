#ifndef FTRANS_MD5
#define FTRANS_MD5
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <bitset>
const unsigned int  MAGIC[4] = {0x67452301L,0xefcdab89L,0x98badcfeL,0x10325476L};
class MD5{
    public:
        // constructors, asssignment, destructor
        MD5(const unsigned char * s, size_t size){
            set(s,size);
        };
        char * get() const{
            char * str = new char[33];
            unsigned char * t =(unsigned char *)md5;
            std::stringstream sio;
            for(int i = 0; i < 16; i++)
                sio<<std::hex<<(int)t[i];
            sio>>str;
            return str;
            
        };
        void set(const unsigned char * str, size_t size){
            size_t fillen = (56 - size % 64 + 64) % 64;
            size_t len = size+fillen+8; 
            memcpy(md5,MAGIC,4*sizeof(int));
            unsigned int N = len / 64;
            unsigned char * buf = new unsigned char [len];
            bzero(buf,len);
            memcpy(buf,str,size);
            buf[size] = (char)-128;
            for(unsigned int i = 0; i < sizeof(size_t); i++)
                buf[size+fillen+i] = (unsigned char)(size*8 >> i*8);
            unsigned int * M = (unsigned int *)buf;
            for(unsigned int i = 0; i < N; i++){
            unsigned int a =  md5[0], b = md5[1], c = md5[2], d = md5[3];
                a=FF(a,b,c,d,M[0],7,0xd76aa478);
                d=FF(d,a,b,c,M[1],12,0xe8c7b756);
                c=FF(c,d,a,b,M[2],17,0x242070db);
                b=FF(b,c,d,a,M[3],22,0xc1bdceee);
                a=FF(a,b,c,d,M[4],7,0xf57c0faf);
                d=FF(d,a,b,c,M[5],12,0x4787c62a);
                c=FF(c,d,a,b,M[6],17,0xa8304613);
                b=FF(b,c,d,a,M[7],22,0xfd469501);
                a=FF(a,b,c,d,M[8],7,0x698098d8);
                d=FF(d,a,b,c,M[9],12,0x8b44f7af);
                c=FF(c,d,a,b,M[10],17,0xffff5bb1);
                b=FF(b,c,d,a,M[11],22,0x895cd7be);
                a=FF(a,b,c,d,M[12],7,0x6b901122);
                d=FF(d,a,b,c,M[13],12,0xfd987193);
                c=FF(c,d,a,b,M[14],17,0xa679438e);
                b=FF(b,c,d,a,M[15],22,0x49b40821);
                a=GG(a,b,c,d,M[1],5,0xf61e2562);
                d=GG(d,a,b,c,M[6],9,0xc040b340);
                c=GG(c,d,a,b,M[11],14,0x265e5a51);
                b=GG(b,c,d,a,M[0],20,0xe9b6c7aa);
                a=GG(a,b,c,d,M[5],5,0xd62f105d);
                d=GG(d,a,b,c,M[10],9,0x02441453);
                c=GG(c,d,a,b,M[15],14,0xd8a1e681);
                b=GG(b,c,d,a,M[4],20,0xe7d3fbc8);
                a=GG(a,b,c,d,M[9],5,0x21e1cde6);
                d=GG(d,a,b,c,M[14],9,0xc33707d6);
                c=GG(c,d,a,b,M[3],14,0xf4d50d87);
                b=GG(b,c,d,a,M[8],20,0x455a14ed);
                a=GG(a,b,c,d,M[13],5,0xa9e3e905);
                d=GG(d,a,b,c,M[2],9,0xfcefa3f8);
                c=GG(c,d,a,b,M[7],14,0x676f02d9);
                b=GG(b,c,d,a,M[12],20,0x8d2a4c8a);
                a=HH(a,b,c,d,M[5],4,0xfffa3942);
                d=HH(d,a,b,c,M[8],11,0x8771f681);
                c=HH(c,d,a,b,M[11],16,0x6d9d6122);
                b=HH(b,c,d,a,M[14],23,0xfde5380c);
                a=HH(a,b,c,d,M[1],4,0xa4beea44);
                d=HH(d,a,b,c,M[4],11,0x4bdecfa9);
                c=HH(c,d,a,b,M[7],16,0xf6bb4b60);
                b=HH(b,c,d,a,M[10],23,0xbebfbc70);
                a=HH(a,b,c,d,M[13],4,0x289b7ec6);
                d=HH(d,a,b,c,M[0],11,0xeaa127fa);
                c=HH(c,d,a,b,M[3],16,0xd4ef3085);
                b=HH(b,c,d,a,M[6],23,0x04881d05);
                a=HH(a,b,c,d,M[9],4,0xd9d4d039);
                d=HH(d,a,b,c,M[12],11,0xe6db99e5);
                c=HH(c,d,a,b,M[15],16,0x1fa27cf8);
                b=HH(b,c,d,a,M[2],23,0xc4ac5665);
                a=II(a,b,c,d,M[0],6,0xf4292244);
                d=II(d,a,b,c,M[7],10,0x432aff97);
                c=II(c,d,a,b,M[14],15,0xab9423a7);
                b=II(b,c,d,a,M[5],21,0xfc93a039);
                a=II(a,b,c,d,M[12],6,0x655b59c3);
                d=II(d,a,b,c,M[3],10,0x8f0ccc92);
                c=II(c,d,a,b,M[10],15,0xffeff47d);
                b=II(b,c,d,a,M[1],21,0x85845dd1);
                a=II(a,b,c,d,M[8],6,0x6fa87e4f);
                d=II(d,a,b,c,M[15],10,0xfe2ce6e0);
                c=II(c,d,a,b,M[6],15,0xa3014314);
                b=II(b,c,d,a,M[13],21,0x4e0811a1);
                a=II(a,b,c,d,M[4],6,0xf7537e82);
                d=II(d,a,b,c,M[11],10,0xbd3af235);
                c=II(c,d,a,b,M[2],15,0x2ad7d2bb);
                b=II(b,c,d,a,M[9],21,0xeb86d391);
                md5[0] += a ;
                md5[1] += b ;
                md5[2] += c ;
                md5[3] += d ;
                M = M + 16;
            }
            M = NULL;
            delete [] buf;
            buf = NULL;
        };
    private:
        unsigned int md5[4];
        unsigned int rotate(unsigned int a, unsigned int s){
            unsigned int n = sizeof(unsigned int) * 8;
            s = s % n; 
            return (a << s ) | (a >> (n - s)) ;

        }
        unsigned int F(unsigned int a, unsigned int b, unsigned int c){
            return (a & b) | (~a & c);
        }
        unsigned int G(unsigned int a, unsigned int b, unsigned int c){
            return (a&c)|(b&(~c));
        }
        unsigned int H(unsigned int a, unsigned int b, unsigned int c){
            return a^b^c;
        }
        unsigned int I(unsigned int a, unsigned int b, unsigned int c){
            return b^(a|(~c));
        }

        unsigned int FF(unsigned int a,unsigned int b,unsigned int c,unsigned int d,unsigned int k,unsigned int s, unsigned int t) { 
            a+=k+t+F(b,c,d); 
            a = rotate(a,s); 
            a+=b; 
            return a;
        };

        unsigned int GG(unsigned int a,unsigned int b,unsigned int c,unsigned int d,unsigned int k,unsigned int s, unsigned int t) { 
            a+=((k)+(t)+G((b),(c),(d))); 
            a=rotate(a,s); 
            a+=b; 
            return a;
        };

        unsigned int HH(unsigned int a,unsigned int b,unsigned int c,unsigned int d,unsigned int k,unsigned int s, unsigned int t) { 
            a+=((k)+(t)+H((b),(c),(d))); 
            a=rotate(a,s); 
            a+=b; 
            return a;
        };

        unsigned int II(unsigned int a,unsigned int b,unsigned int c,unsigned int d,unsigned int k,unsigned int s, unsigned int t) { 
            a+=((k)+(t)+I((b),(c),(d))); 
            a=rotate(a,s); 
            a+=b; 
            return a;
        };
};


char * MD5(int fd ){
    if(fd <= 0){
        errno = ENOENT;
        return NULL;
    }
    struct stat fs;
    fstat(fd,&fs); 
    size_t flen = fs.st_size;
    unsigned char * buf = new unsigned char[flen];
    if(!read(fd,buf,flen))
        return NULL;
    class MD5 M(buf, flen);
    return  M.get(); 
} 
#endif
