xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 36;
 -283.89156;752.11842;100.00000;,
 -155.03694;835.72169;100.00000;,
 -155.03694;835.72169;-100.00000;,
 -283.89156;752.11842;-100.00000;,
 -330.71280;0.00000;-100.00000;,
 -173.77309;0.00000;-100.00000;,
 -173.77309;0.00000;100.00000;,
 -330.71280;0.00000;100.00000;,
 -173.77309;571.39893;-100.00000;,
 -330.71280;625.26417;-100.00000;,
 -173.77309;571.39893;100.00000;,
 -330.71280;625.26417;100.00000;,
 -114.00364;645.40333;100.00000;,
 -114.00364;645.40333;-100.00000;,
 0.00000;670.15182;-100.00000;,
 0.00000;670.15182;100.00000;,
 -77.03948;858.16554;-100.00000;,
 0.00000;867.14308;-100.00000;,
 -77.03948;858.16554;100.00000;,
 0.00000;867.14308;100.00000;,
 283.89156;752.11842;-100.00000;,
 155.03694;835.72169;-100.00000;,
 155.03694;835.72169;100.00000;,
 283.89156;752.11842;100.00000;,
 330.71280;0.00000;100.00000;,
 173.77309;0.00000;100.00000;,
 173.77309;0.00000;-100.00000;,
 330.71280;0.00000;-100.00000;,
 330.71280;625.26417;-100.00000;,
 173.77309;571.39893;-100.00000;,
 173.77309;571.39893;100.00000;,
 330.71280;625.26417;100.00000;,
 114.00364;645.40333;-100.00000;,
 114.00364;645.40333;100.00000;,
 77.03948;858.16554;-100.00000;,
 77.03948;858.16554;100.00000;;
 
 34;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,5,4,9;,
 4;8,9,3,2;,
 4;10,6,5,8;,
 4;11,7,6,10;,
 4;11,10,1,0;,
 4;9,4,7,11;,
 4;9,11,0,3;,
 4;12,10,8,13;,
 4;12,13,14,15;,
 4;13,8,2,16;,
 4;13,16,17,14;,
 4;16,2,1,18;,
 4;16,18,19,17;,
 4;18,1,10,12;,
 4;18,12,15,19;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,27,26,29;,
 4;21,20,28,29;,
 4;29,26,25,30;,
 4;30,25,24,31;,
 4;23,22,30,31;,
 4;31,24,27,28;,
 4;20,23,31,28;,
 4;32,29,30,33;,
 4;15,14,32,33;,
 4;34,21,29,32;,
 4;14,17,34,32;,
 4;35,22,21,34;,
 4;17,19,35,34;,
 4;33,30,22,35;,
 4;19,15,33,35;;
 
 MeshMaterialList {
  1;
  34;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\BlockRunGame93047.png";
   }
  }
 }
 MeshNormals {
  43;
  -0.781071;0.624443;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.414927;0.909855;0.000000;,
  0.000000;-0.000000;-1.000000;,
  0.000000;-0.000000;-1.000000;,
  0.942857;-0.333198;-0.000000;,
  0.000000;-0.000000;1.000000;,
  0.000000;-0.000000;-1.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.000000;-1.000000;,
  -0.196802;0.980443;0.000000;,
  0.524893;-0.851168;-0.000000;,
  0.781071;0.624443;0.000000;,
  0.414927;0.909855;0.000000;,
  -0.000000;-0.000000;-1.000000;,
  -0.000000;-0.000000;-1.000000;,
  -0.942857;-0.333198;0.000000;,
  -0.000000;-0.000000;1.000000;,
  -0.000000;-0.000000;-1.000000;,
  0.196802;0.980443;0.000000;,
  -0.524893;-0.851168;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;-0.000000;-1.000000;,
  0.000000;-0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;-0.000000;1.000000;,
  0.000000;-0.000000;1.000000;,
  0.000000;-0.000000;1.000000;,
  -0.984413;0.175872;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.000000;1.000000;,
  0.000000;-0.000000;1.000000;,
  -0.000000;0.000000;-1.000000;,
  -0.000000;-0.000000;-1.000000;,
  -0.000000;-0.000000;-1.000000;,
  -0.000000;-0.000000;1.000000;,
  -0.000000;0.000000;1.000000;,
  -0.000000;-0.000000;1.000000;,
  -0.000000;-0.000000;1.000000;,
  0.984413;0.175872;0.000000;,
  -0.000000;-0.000000;1.000000;;
  34;
  4;0,2,2,0;,
  4;1,1,1,1;,
  4;4,22,22,3;,
  4;4,3,23,24;,
  4;5,25,25,5;,
  4;6,26,26,27;,
  4;6,27,28,29;,
  4;30,31,31,30;,
  4;30,30,0,0;,
  4;12,5,5,12;,
  4;12,12,9,9;,
  4;10,4,24,10;,
  4;10,10,7,7;,
  4;11,2,2,11;,
  4;11,11,8,8;,
  4;32,28,27,32;,
  4;32,32,33,33;,
  4;13,14,14,13;,
  4;1,1,1,1;,
  4;15,34,34,16;,
  4;35,36,15,16;,
  4;17,31,31,17;,
  4;37,38,38,18;,
  4;39,40,37,18;,
  4;41,25,25,41;,
  4;13,13,41,41;,
  4;21,17,17,21;,
  4;9,9,21,21;,
  4;19,35,16,19;,
  4;7,7,19,19;,
  4;20,14,14,20;,
  4;8,8,20,20;,
  4;42,37,40,42;,
  4;33,33,42,42;;
 }
 MeshTextureCoords {
  36;
  -0.872301;-3.490444;,
  0.344665;-3.948694;,
  0.675047;-2.463980;,
  -0.541919;-2.005730;,
  -2.120406;1.442754;,
  -0.798501;1.347655;,
  -1.128884;-0.137059;,
  -2.450788;-0.041960;,
  0.101091;-1.250670;,
  -1.136010;-1.400514;,
  -0.229291;-2.735384;,
  -1.466392;-2.885228;,
  0.390658;-3.108122;,
  0.721040;-1.623409;,
  1.720257;-1.805028;,
  1.389875;-3.289742;,
  1.367356;-2.613302;,
  2.030394;-2.700808;,
  1.036973;-4.098016;,
  1.700011;-4.185522;,
  4.240524;-2.349781;,
  3.286803;-2.651870;,
  2.956420;-4.136584;,
  3.910141;-3.834495;,
  3.120406;-0.442754;,
  1.798501;-0.347655;,
  2.128884;1.137058;,
  3.450788;1.041960;,
  4.435184;-1.801307;,
  3.028476;-1.461267;,
  2.698094;-2.945981;,
  4.104802;-3.286021;,
  2.641548;-1.761570;,
  2.311165;-3.246284;,
  2.665164;-2.706666;,
  2.334782;-4.191381;;
 }
}
