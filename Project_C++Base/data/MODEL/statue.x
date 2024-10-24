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
 17;
 -65.52963;0.00000;-68.48992;,
 17.74567;0.00005;-5.95035;,
 -7.31732;0.00005;26.41949;,
 -90.59260;0.00005;-36.12010;,
 -23.41667;0.00005;-73.06146;,
 11.07708;0.00005;-47.15672;,
 -49.43029;0.00005;30.99103;,
 -83.92402;0.00005;5.08625;,
 80.13667;395.04307;44.82621;,
 125.08064;386.37781;17.25991;,
 94.42328;399.38096;-6.47695;,
 129.41016;378.45079;57.14495;,
 104.87608;380.24305;89.81387;,
 65.85010;390.70504;96.12957;,
 35.19287;403.70826;72.39241;,
 30.86312;411.63541;32.50726;,
 55.39705;409.84288;-0.16142;;
 
 19;
 4;0,1,2,3;,
 4;0,4,5,1;,
 4;2,6,7,3;,
 3;8,9,10;,
 3;8,11,9;,
 3;8,12,11;,
 3;8,13,12;,
 3;8,14,13;,
 3;8,15,14;,
 3;8,16,15;,
 3;8,10,16;,
 4;5,4,10,9;,
 4;1,5,9,11;,
 4;2,1,11,12;,
 4;6,2,12,13;,
 4;7,6,13,14;,
 4;3,7,14,15;,
 4;0,3,15,16;,
 4;4,0,16,10;;
 
 MeshMaterialList {
  1;
  19;
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
    "C:\\Users\\student\\Downloads\\BlockRunGame93047.png";
   }
  }
 }
 MeshNormals {
  19;
  0.000001;-1.000000;-0.000001;,
  -0.000000;-1.000000;0.000001;,
  0.000000;-1.000000;-0.000000;,
  0.279447;0.947089;0.157899;,
  0.279446;0.947089;0.157897;,
  0.279445;0.947089;0.157902;,
  0.279447;0.947089;0.157901;,
  0.279447;0.947088;0.157901;,
  0.279446;0.947089;0.157898;,
  0.279447;0.947090;0.157895;,
  0.279443;0.947090;0.157898;,
  0.599932;-0.043830;-0.798849;,
  0.954307;-0.255827;-0.154437;,
  0.749662;-0.317963;0.580437;,
  0.105873;-0.193842;0.975303;,
  -0.599935;0.043831;0.798847;,
  -0.954307;0.255826;0.154440;,
  -0.749661;0.317962;-0.580438;,
  -0.105871;0.193840;-0.975304;;
  19;
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  3;3,3,3;,
  3;4,4,4;,
  3;5,5,5;,
  3;6,6,6;,
  3;7,7,7;,
  3;8,8,8;,
  3;9,9,9;,
  3;10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;18,18,18,18;;
 }
 MeshTextureCoords {
  17;
  -1.383472;-2.790248;,
  0.065044;1.328588;,
  1.603849;0.219406;,
  0.155333;-3.899428;,
  -2.047311;-0.799559;,
  -1.447316;0.906517;,
  2.267690;-1.771282;,
  1.667693;-3.477358;,
  13.006661;10.452053;,
  11.166265;12.386538;,
  10.990771;11.066795;,
  12.419854;12.573074;,
  14.017179;11.517150;,
  15.022554;9.837312;,
  14.847050;8.517576;,
  13.593464;8.331030;,
  11.996142;9.386944;;
 }
}
