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
 50;
 0.00000;3.87313;-51.50093;,
 57.29577;3.87313;-51.50093;,
 55.05469;-3.98615;-48.94879;,
 0.00000;-3.98615;-48.94879;,
 -55.05469;-3.98615;-48.94879;,
 -57.29577;3.87313;-51.50093;,
 0.00000;3.87313;-2.03323;,
 -57.29577;3.87313;-2.03322;,
 -55.05469;-3.98615;3.07108;,
 0.00000;-3.98615;3.07108;,
 55.05469;-3.98615;3.07108;,
 57.29577;3.87313;-2.03322;,
 57.29577;3.87313;-21.56273;,
 55.05469;-3.98615;-17.47923;,
 55.05469;-3.98615;-48.94879;,
 57.29577;3.87313;-51.50093;,
 -57.29577;3.87313;-21.56273;,
 -57.29577;3.87313;-51.50093;,
 -55.05469;-3.98615;-48.94879;,
 -55.05469;-3.98615;-17.47923;,
 57.29577;3.87313;-21.56273;,
 57.29577;3.87313;-51.50093;,
 0.00000;3.87313;-51.50093;,
 0.00000;3.87313;-45.04246;,
 -57.29577;3.87313;-51.50093;,
 -57.29577;3.87313;-21.56273;,
 55.05469;-3.98615;-17.47923;,
 0.00000;-3.98615;-40.95902;,
 0.00000;-3.98615;-48.94879;,
 55.05469;-3.98615;-48.94879;,
 -55.05469;-3.98615;-17.47923;,
 -55.05469;-3.98615;-48.94879;,
 57.29577;3.87313;-13.39581;,
 57.29577;3.87313;-2.03322;,
 55.05469;-3.98615;3.07108;,
 55.05469;-3.98615;-17.47923;,
 -55.05469;-3.98615;-17.47923;,
 -55.05469;-3.98615;3.07108;,
 -57.29577;3.87313;-2.03322;,
 -57.29577;3.87313;-13.39581;,
 0.00000;3.87313;-36.87557;,
 0.00000;3.87313;-2.03323;,
 57.29577;3.87313;-13.39581;,
 -57.29577;3.87313;-13.39581;,
 55.05469;-3.98615;-17.47923;,
 0.00000;-3.98615;3.07108;,
 0.00000;-3.98615;-40.95902;,
 -55.05469;-3.98615;-17.47923;,
 55.05469;-3.98615;-17.47923;,
 -55.05469;-3.98615;-17.47923;;
 
 20;
 4;0,1,2,3;,
 4;0,3,4,5;,
 4;6,7,8,9;,
 4;6,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,21,22,23;,
 4;23,22,24,25;,
 4;26,27,28,29;,
 4;27,30,31,28;,
 4;32,33,34,35;,
 4;36,37,38,39;,
 4;40,41,33,42;,
 4;40,42,20,23;,
 4;43,38,41,40;,
 4;43,40,23,25;,
 4;44,34,45,46;,
 4;46,45,37,47;,
 3;48,12,32;,
 3;49,39,16;;
 
 MeshMaterialList {
  3;
  20;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  1,
  2,
  1,
  1,
  1,
  1;;
  Material {
   0.112941;0.097255;0.323137;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.668235;0.668235;0.668235;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.768627;0.222745;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  16;
  0.000000;-0.308854;-0.951109;,
  -0.000000;0.878826;0.477142;,
  -0.000000;0.544671;0.838650;,
  0.000000;0.878826;0.477142;,
  0.000000;0.544671;0.838650;,
  0.000000;-0.308854;-0.951110;,
  0.000000;0.878826;0.477142;,
  0.000000;0.544671;0.838650;,
  -0.961667;-0.274220;0.000000;,
  0.961667;-0.274220;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.961667;-0.274219;-0.000000;,
  -0.961667;-0.274219;0.000000;,
  0.961667;-0.274220;-0.000000;,
  -0.961667;-0.274220;0.000000;;
  20;
  4;5,0,0,5;,
  4;5,5,0,0;,
  4;6,3,4,7;,
  4;6,7,2,1;,
  4;9,9,12,12;,
  4;8,13,13,8;,
  4;10,10,10,10;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;9,14,14,9;,
  4;8,15,15,8;,
  4;10,6,1,10;,
  4;10,10,10,10;,
  4;10,3,6,10;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  3;9,9,9;,
  3;8,8,8;;
 }
 MeshTextureCoords {
  50;
  0.550327;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.547758;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.449673;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.452242;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.419476;0.000000;,
  0.367884;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.580524;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.632116;1.000000;,
  1.000000;0.580524;,
  1.000000;1.000000;,
  0.550327;1.000000;,
  0.550327;0.580524;,
  0.000000;1.000000;,
  0.000000;0.580524;,
  1.000000;0.367884;,
  0.547758;0.367884;,
  0.547758;0.000000;,
  1.000000;0.000000;,
  0.000000;0.367884;,
  0.000000;0.000000;,
  0.584571;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.532979;1.000000;,
  0.467021;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.415429;0.000000;,
  0.550327;0.415429;,
  0.550327;0.000000;,
  1.000000;0.415429;,
  0.000000;0.415429;,
  1.000000;0.532979;,
  0.547758;1.000000;,
  0.547758;0.532979;,
  0.000000;0.532979;,
  0.450431;1.000000;,
  0.549569;1.000000;;
 }
}