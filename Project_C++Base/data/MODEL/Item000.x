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
 35;
 0.00000;-113.61530;0.00000;,
 -0.00000;-127.81713;14.20191;,
 110.69306;-63.90856;14.20192;,
 98.39381;-56.80765;0.00000;,
 -0.00000;-142.01922;-0.00000;,
 122.99223;-71.00961;0.00000;,
 0.00000;-127.81713;-14.20191;,
 110.69306;-63.90856;-14.20191;,
 0.00000;-113.61530;0.00000;,
 98.39381;-56.80765;0.00000;,
 110.69306;63.90856;14.20192;,
 98.39381;56.80765;0.00000;,
 122.99223;71.00958;0.00000;,
 110.69306;63.90856;-14.20191;,
 98.39381;56.80765;0.00000;,
 0.00001;127.81713;14.20191;,
 0.00001;113.61530;0.00000;,
 0.00001;142.01922;-0.00000;,
 0.00001;127.81713;-14.20191;,
 0.00001;113.61530;0.00000;,
 -110.69306;63.90856;14.20191;,
 -98.39380;56.80765;-0.00000;,
 -122.99223;71.00958;-0.00001;,
 -110.69306;63.90856;-14.20192;,
 -98.39380;56.80765;-0.00000;,
 -110.69306;-63.90856;14.20191;,
 -98.39380;-56.80765;-0.00000;,
 -122.99223;-71.00958;-0.00001;,
 -110.69306;-63.90856;-14.20192;,
 -98.39380;-56.80765;-0.00000;,
 -0.00000;-127.81713;14.20191;,
 0.00000;-113.61530;0.00000;,
 -0.00000;-142.01922;-0.00000;,
 0.00000;-127.81713;-14.20191;,
 0.00000;-113.61530;0.00000;;
 
 24;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;3,2,10,11;,
 4;2,5,12,10;,
 4;5,7,13,12;,
 4;7,9,14,13;,
 4;11,10,15,16;,
 4;10,12,17,15;,
 4;12,13,18,17;,
 4;13,14,19,18;,
 4;16,15,20,21;,
 4;15,17,22,20;,
 4;17,18,23,22;,
 4;18,19,24,23;,
 4;21,20,25,26;,
 4;20,22,27,25;,
 4;22,23,28,27;,
 4;23,24,29,28;,
 4;26,25,30,31;,
 4;25,27,32,30;,
 4;27,28,33,32;,
 4;28,29,34,33;;
 
 MeshMaterialList {
  2;
  24;
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
   0.800000;0.724706;0.000000;1.000000;;
   5.000000;
   0.120000;0.120000;0.120000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  24;
  -0.377965;0.654655;0.654652;,
  0.377963;-0.654652;0.654657;,
  0.377963;-0.654651;-0.654657;,
  -0.755928;0.000000;0.654655;,
  0.755930;0.000000;0.654652;,
  0.755930;0.000000;-0.654652;,
  -0.377965;-0.654655;0.654652;,
  0.377963;0.654652;0.654656;,
  0.377963;0.654652;-0.654656;,
  0.377965;-0.654655;0.654652;,
  -0.377963;0.654652;0.654656;,
  -0.377963;0.654652;-0.654656;,
  0.755928;0.000000;0.654655;,
  -0.755930;0.000000;0.654652;,
  -0.755930;0.000000;-0.654652;,
  -0.377965;0.654655;-0.654652;,
  -0.755928;0.000000;-0.654655;,
  -0.377965;-0.654655;-0.654652;,
  0.377965;-0.654655;-0.654652;,
  0.755928;0.000000;-0.654655;,
  0.377965;0.654655;0.654652;,
  -0.377963;-0.654652;0.654656;,
  -0.377963;-0.654652;-0.654656;,
  0.377965;0.654655;-0.654652;;
  24;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;15,15,15,15;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;16,16,16,16;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;17,17,17,17;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;18,18,18,18;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;22,22,22,22;,
  4;23,23,23,23;;
 }
 MeshTextureCoords {
  35;
  0.000000;0.000000;,
  0.000000;0.250000;,
  0.166667;0.250000;,
  0.166667;0.000000;,
  0.000000;0.500000;,
  0.166667;0.500000;,
  0.000000;0.750000;,
  0.166667;0.750000;,
  0.000000;1.000000;,
  0.166667;1.000000;,
  0.333333;0.250000;,
  0.333333;0.000000;,
  0.333333;0.500000;,
  0.333333;0.750000;,
  0.333333;1.000000;,
  0.500000;0.250000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.500000;0.750000;,
  0.500000;1.000000;,
  0.666667;0.250000;,
  0.666667;0.000000;,
  0.666667;0.500000;,
  0.666667;0.750000;,
  0.666667;1.000000;,
  0.833333;0.250000;,
  0.833333;0.000000;,
  0.833333;0.500000;,
  0.833333;0.750000;,
  0.833333;1.000000;,
  1.000000;0.250000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  1.000000;0.750000;,
  1.000000;1.000000;;
 }
}
