#pragma once

#define SizeOf(n) sizeof(n)
#define CountOf(n) (SizeOf(n) / SizeOf((n)[0]))

#define Kilobytes(n) (1024ULL * (n))
#define Megabytes(n) (1024ULL * Kilobytes(n))
#define Gigabytes(n) (1024ULL * Megabytes(n))
#define Terabytes(n) (1024ULL * Gigabytes(n))
