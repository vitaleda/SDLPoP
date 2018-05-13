/*
SDLPoP, a port/conversion of the DOS game Prince of Persia.
Copyright (C) 2013-2018  Dávid Nagy

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

The authors of this program may be contacted at http://forum.princed.org
*/

const char mask_img[664] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00,
	0x0d, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00,
	0x00, 0x64, 0x08, 0x02, 0x00, 0x00, 0x00, 0xff, 0x80, 0x02, 0x03,
	0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 0x42, 0x00, 0xae, 0xce,
	0x1c, 0xe9, 0x00, 0x00, 0x00, 0x04, 0x67, 0x41, 0x4d, 0x41, 0x00,
	0x00, 0xb1, 0x8f, 0x0b, 0xfc, 0x61, 0x05, 0x00, 0x00, 0x00, 0x20,
	0x63, 0x48, 0x52, 0x4d, 0x00, 0x00, 0x7a, 0x26, 0x00, 0x00, 0x80,
	0x84, 0x00, 0x00, 0xfa, 0x00, 0x00, 0x00, 0x80, 0xe8, 0x00, 0x00,
	0x75, 0x30, 0x00, 0x00, 0xea, 0x60, 0x00, 0x00, 0x3a, 0x98, 0x00,
	0x00, 0x17, 0x70, 0x9c, 0xba, 0x51, 0x3c, 0x00, 0x00, 0x02, 0x16,
	0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0xed, 0xdb, 0x51, 0x72, 0x83,
	0x30, 0x0c, 0x04, 0xd0, 0x72, 0xff, 0x43, 0x53, 0x3a, 0xe9, 0xd0,
	0x34, 0x21, 0xc6, 0x6b, 0x5b, 0xb6, 0xb4, 0xda, 0x7c, 0x2f, 0xc2,
	0x7a, 0x08, 0x4f, 0x98, 0x90, 0xed, 0xcb, 0xc7, 0x67, 0xdf, 0xf7,
	0xc2, 0x42, 0xb6, 0x6d, 0xf3, 0xb1, 0xcc, 0xe9, 0xab, 0x38, 0x5c,
	0x86, 0x7c, 0xa6, 0x2f, 0x7c, 0xe2, 0x09, 0x87, 0x00, 0x5d, 0x16,
	0x99, 0xd8, 0x84, 0xf1, 0xa9, 0xec, 0x8c, 0xde, 0x2b, 0x1b, 0xb7,
	0x62, 0x59, 0x7e, 0x26, 0xd3, 0xf3, 0xb9, 0x2c, 0x7b, 0x32, 0xa8,
	0xbd, 0x8a, 0x29, 0x18, 0x99, 0x07, 0xa6, 0x00, 0x64, 0xde, 0x98,
	0x9c, 0x92, 0x79, 0x66, 0xf2, 0x45, 0x16, 0x45, 0xea, 0xb1, 0x4e,
	0x83, 0xfd, 0xb9, 0xba, 0x64, 0x2c, 0xa9, 0x95, 0x5e, 0x11, 0xa5,
	0x16, 0x78, 0xc5, 0x65, 0x9a, 0xbd, 0x85, 0x71, 0x48, 0xcd, 0x18,
	0x31, 0x26, 0x29, 0x5b, 0x2f, 0x3e, 0x29, 0x2b, 0x2f, 0x56, 0xa9,
	0xf1, 0x5e, 0xdc, 0x52, 0x83, 0xbd, 0x84, 0x55, 0xfb, 0xd5, 0x33,
	0x83, 0xd4, 0x98, 0xe1, 0xca, 0x23, 0xd5, 0xeb, 0x95, 0x4d, 0xaa,
	0xdd, 0x2b, 0xa7, 0x54, 0xa3, 0x97, 0xb0, 0xb4, 0xa9, 0xd7, 0xce,
	0x40, 0xad, 0xd4, 0x91, 0xab, 0x2d, 0xc9, 0x9b, 0xab, 0xc5, 0xe2,
	0x15, 0xc0, 0x3a, 0xab, 0xf2, 0xc2, 0x4a, 0xf2, 0xa6, 0xef, 0xb1,
	0x78, 0x7b, 0x6f, 0xe9, 0xec, 0xc6, 0xab, 0xa5, 0x24, 0xef, 0x31,
	0x25, 0x2c, 0xde, 0xae, 0xdb, 0x3b, 0xfb, 0xe8, 0xd5, 0x5e, 0x92,
	0xf7, 0xc8, 0x6b, 0x2c, 0xde, 0x7e, 0x7b, 0x3b, 0xbb, 0xf0, 0xea,
	0x2d, 0xc9, 0x7b, 0xbc, 0xb0, 0x80, 0x6b, 0xfb, 0x8a, 0x05, 0x1c,
	0x9a, 0x32, 0xfa, 0xcf, 0x2b, 0xa5, 0x00, 0xd0, 0xb4, 0xb0, 0x9a,
	0xb0, 0x80, 0x83, 0x12, 0x47, 0x7f, 0x87, 0x2b, 0xb1, 0x00, 0xd0,
	0xba, 0xb0, 0x84, 0x05, 0x08, 0x00, 0x51, 0x4d, 0x96, 0xb0, 0x00,
	0x01, 0x20, 0xaa, 0xc9, 0x02, 0xb1, 0x80, 0x78, 0xfa, 0xa8, 0x7e,
	0x9b, 0x00, 0x46, 0x40, 0x58, 0xc2, 0x02, 0x04, 0x80, 0xa8, 0x26,
	0x4b, 0x58, 0x80, 0x00, 0x10, 0xd5, 0x64, 0x09, 0x0b, 0x10, 0x00,
	0xa2, 0x9a, 0x2c, 0x61, 0x01, 0x02, 0x40, 0xf4, 0xe7, 0x89, 0x07,
	0x88, 0x27, 0x8e, 0xea, 0xd9, 0x10, 0xb8, 0xf8, 0xc2, 0x12, 0x16,
	0x20, 0x00, 0x44, 0x35, 0x59, 0xc2, 0x02, 0x04, 0x80, 0xa8, 0x26,
	0x0b, 0xc7, 0xd2, 0xb7, 0x87, 0x5b, 0x33, 0xfd, 0x22, 0x7d, 0x4b,
	0xf4, 0x17, 0x10, 0x56, 0x2b, 0x96, 0xee, 0xc4, 0x82, 0x9c, 0xde,
	0xcf, 0xea, 0x18, 0x2b, 0x4d, 0x16, 0x36, 0x59, 0xf2, 0xba, 0xf4,
	0xd2, 0xdb, 0xca, 0x7d, 0xf7, 0xe0, 0xe9, 0x07, 0x94, 0x49, 0x10,
	0xd5, 0x3f, 0x2c, 0x80, 0x8b, 0xac, 0xbf, 0xef, 0xd4, 0x62, 0xdd,
	0x4b, 0x69, 0x9b, 0x3f, 0x2d, 0xab, 0xb0, 0xe4, 0x75, 0x78, 0xd5,
	0x4a, 0x09, 0x0b, 0xc3, 0x4a, 0xee, 0x05, 0x8c, 0xd5, 0x23, 0x5a,
	0xbb, 0x0d, 0x32, 0xe6, 0x60, 0xac, 0xb4, 0x5e, 0x2d, 0x52, 0x39,
	0xe7, 0xab, 0x5d, 0x2a, 0x9b, 0x57, 0xaf, 0x54, 0x1e, 0xaf, 0x31,
	0x52, 0x49, 0x36, 0xaf, 0x61, 0x58, 0xf4, 0x5e, 0x23, 0xa5, 0xb8,
	0x6f, 0xc6, 0xf1, 0x52, 0xac, 0x5e, 0x56, 0x52, 0x7c, 0x5e, 0xb6,
	0x52, 0x4c, 0x5e, 0x33, 0xa4, 0xce, 0x73, 0xc4, 0x7d, 0xce, 0x99,
	0xca, 0x14, 0xda, 0x6b, 0x8d, 0x54, 0xc4, 0x5b, 0x72, 0xa5, 0x54,
	0x2c, 0xaf, 0xf5, 0x52, 0x21, 0x6e, 0x49, 0x47, 0x4c, 0xcf, 0x4b,
	0xf1, 0xb6, 0xeb, 0x3b, 0x65, 0xf2, 0x46, 0x16, 0x80, 0xc9, 0x03,
	0x59, 0x30, 0xa6, 0x55, 0x64, 0x81, 0x99, 0x5e, 0x96, 0x6e, 0xb7,
	0x9d, 0xf1, 0x18, 0xbd, 0x77, 0x32, 0x4a, 0x8d, 0xd9, 0xa8, 0xdc,
	0x5b, 0x59, 0xd0, 0x89, 0xcb, 0x37, 0x89, 0x47, 0xeb, 0x0a, 0x65,
	0x68, 0xb9, 0xa7, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44,
	0xae, 0x42, 0x60, 0x82
};

const int mask_img_length = 664;
