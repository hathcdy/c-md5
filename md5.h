#ifndef MD5_H
#define MD5_H

#include <string>

typedef unsigned char byte;
typedef unsigned long ulong;

using std::string;
using std::ifstream;

class MD5 {
public:
	MD5();
	MD5(const void *input, size_t length);
	MD5(const string &str);
	void update(const string &str);	
	const byte* digest();
	string toString();
	void reset();
private:
	void update(const byte *input, size_t length);
	void final();
	void transform(const byte block[64]);
	void encode(const ulong *input, byte *output, size_t length);
	void decode(const byte *input, ulong *output, size_t length);
	string bytesToHexString(const byte *input, size_t length);
	
private:
	ulong _state[4];	/* ABCD */
	ulong _count[2];	/* 计数器count */
	byte _buffer[64];	/* 缓冲 */
	byte _digest[16];	/* 消息摘要 */
	bool _finished;		/* 计算是否完成 */

	static const byte PADDING[64];	/* 填充 */
	static const char HEX[16];
	static const size_t BUFFER_SIZE = 1024;
};

#endif