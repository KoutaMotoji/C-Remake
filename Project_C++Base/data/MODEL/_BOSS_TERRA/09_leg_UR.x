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
 74;
 96.70878;-4.29262;-90.50711;,
 96.70878;-4.29262;89.00772;,
 113.68982;-206.60435;89.00772;,
 113.68982;-206.60435;-90.50711;,
 96.70878;-4.29262;89.00772;,
 -82.80635;-51.91636;57.12062;,
 -77.76117;-206.60435;89.00772;,
 113.68982;-206.60435;89.00772;,
 -82.80635;-51.91636;57.12062;,
 -82.80635;-51.91636;-58.62036;,
 -77.76117;-206.60435;-90.50711;,
 -77.76117;-206.60435;89.00772;,
 70.25729;34.31566;62.55649;,
 -56.35488;-13.30822;40.06645;,
 -56.35488;-13.30822;-41.56580;,
 70.25729;34.31566;-64.05603;,
 96.70878;-4.29262;-90.50711;,
 -82.80635;-51.91636;-58.62036;,
 77.59901;-386.23272;69.89813;,
 77.59901;-386.23272;-71.39793;,
 113.68982;-206.60435;-90.50711;,
 -45.83771;-386.23272;69.89813;,
 -45.83771;-386.23272;-71.39793;,
 -77.76117;-206.60435;-90.50711;,
 72.83447;-48.15353;-153.29463;,
 -58.93216;-95.77702;-153.29463;,
 -82.80635;-51.91636;-58.62036;,
 96.70878;-4.29262;-90.50711;,
 87.83214;-205.92832;-170.15082;,
 113.68982;-206.60435;-90.50711;,
 -54.88038;-205.92832;-170.15082;,
 -77.76117;-206.60435;-90.50711;,
 -27.04645;-303.50083;-150.74191;,
 58.80792;-303.50083;-150.74191;,
 -54.88038;-205.92832;-170.15082;,
 87.83214;-205.92832;-170.15082;,
 98.57775;81.15181;52.15179;,
 98.57775;81.15181;-53.65108;,
 113.67814;29.07808;74.25559;,
 113.67814;29.07808;-75.75535;,
 160.27493;-19.07638;94.26552;,
 157.71779;-19.85633;-96.31326;,
 107.56507;-37.16072;94.81356;,
 105.00820;-37.94013;-95.76485;,
 193.40321;-261.99649;19.33730;,
 193.10962;-262.24146;-20.86611;,
 184.28568;-267.68174;19.45298;,
 183.99199;-267.92681;-20.75058;,
 46.05065;-405.94483;-95.35183;,
 46.05065;-478.43419;-53.49978;,
 -31.61032;-478.43419;-53.49978;,
 -31.61032;-405.94483;-95.35183;,
 46.05065;-478.43419;30.20390;,
 -31.61032;-478.43419;30.20390;,
 46.05065;-405.94483;72.05572;,
 -31.61032;-405.94483;72.05572;,
 46.05065;-333.45567;30.20390;,
 -13.75103;-333.45567;30.20390;,
 46.05065;-333.45567;-53.49978;,
 -13.75103;-333.45567;-53.49978;,
 46.05065;-405.94483;-95.35183;,
 -31.61032;-405.94483;-95.35183;,
 46.05065;-405.94483;-11.64791;,
 46.05065;-405.94483;-11.64791;,
 46.05065;-405.94483;-11.64791;,
 46.05065;-405.94483;-11.64791;,
 46.05065;-405.94483;-11.64791;,
 46.05065;-405.94483;-11.64791;,
 -31.61032;-405.94483;-11.64791;,
 -31.61032;-405.94483;-11.64791;,
 -31.61032;-405.94483;-11.64791;,
 -31.61032;-405.94483;-11.64791;,
 -31.61032;-405.94483;-11.64791;,
 -31.61032;-405.94483;-11.64791;;
 
 50;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,8,1;,
 4;14,15,16,17;,
 4;13,14,17,8;,
 4;13,12,15,14;,
 4;18,19,20,2;,
 4;21,18,2,11;,
 4;22,21,11,23;,
 4;22,19,18,21;,
 4;24,25,26,27;,
 4;28,24,27,29;,
 4;25,30,31,26;,
 4;25,24,28,30;,
 4;32,33,19,22;,
 4;34,32,22,23;,
 4;33,35,20,19;,
 4;33,32,34,35;,
 4;36,37,15,12;,
 4;38,36,12,1;,
 4;37,39,16,15;,
 4;37,36,38,39;,
 4;40,41,39,38;,
 4;42,40,38,1;,
 4;43,42,1,16;,
 4;41,43,16,39;,
 4;44,45,41,40;,
 4;46,44,40,42;,
 4;47,46,42,43;,
 4;45,47,43,41;,
 4;45,44,46,47;,
 4;48,49,50,51;,
 4;49,52,53,50;,
 4;52,54,55,53;,
 4;54,56,57,55;,
 4;56,58,59,57;,
 4;58,60,61,59;,
 3;62,49,48;,
 3;63,52,49;,
 3;64,54,52;,
 3;65,56,54;,
 3;66,58,56;,
 3;67,60,58;,
 3;68,51,50;,
 3;69,50,53;,
 3;70,53,55;,
 3;71,55,57;,
 3;72,57,59;,
 3;73,59,61;;
 
 MeshMaterialList {
  9;
  50;
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
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.169412;0.232157;0.737255;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.288627;0.288627;0.288627;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.131765;0.131765;0.131765;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.021961;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.034510;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.627451;0.627451;0.627451;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  41;
  -0.999469;-0.032598;0.000000;,
  0.996496;0.083641;0.000000;,
  -0.086415;0.094668;0.991751;,
  -0.293974;0.468557;-0.833087;,
  -0.293974;0.468556;0.833088;,
  -0.984572;-0.174978;0.000000;,
  0.980407;-0.196983;-0.000000;,
  0.000000;-0.105787;0.994389;,
  -0.302331;0.832688;-0.463926;,
  -0.964207;0.013801;-0.264791;,
  0.930052;0.099669;-0.353651;,
  0.000000;-0.692175;-0.721730;,
  -0.192659;0.402156;-0.895072;,
  -0.192654;0.402156;0.895073;,
  -0.855725;0.517432;0.000000;,
  -0.961240;-0.275624;0.007016;,
  -0.014106;0.280664;0.959702;,
  0.729721;0.683716;-0.006344;,
  -0.946996;-0.321041;0.011449;,
  0.138404;-0.267287;0.953626;,
  0.989997;0.140659;-0.010975;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.500003;-0.866024;,
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.500001;0.866025;,
  0.000000;0.500002;0.866024;,
  0.000000;1.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.824955;0.565199;0.000000;,
  -0.352059;0.935978;0.000000;,
  -0.018563;0.127029;-0.991725;,
  -0.902658;-0.258599;-0.343999;,
  0.888511;-0.274830;-0.367447;,
  0.000000;-0.195095;-0.980784;,
  0.960434;0.278507;0.000000;,
  -0.022238;0.271751;-0.962111;,
  0.118807;-0.272189;-0.954881;,
  0.529128;-0.848541;0.001307;,
  0.000000;0.500004;-0.866023;,
  -0.970966;0.239219;0.000000;,
  -0.970966;0.239219;0.000000;;
  50;
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;5,5,5,5;,
  4;23,23,23,23;,
  4;8,8,8,8;,
  4;10,10,10,10;,
  4;9,9,9,9;,
  4;30,30,30,30;,
  4;11,11,11,11;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;33,33,33,33;,
  4;14,14,14,14;,
  4;13,13,13,13;,
  4;12,12,12,12;,
  4;34,34,34,34;,
  4;17,17,17,17;,
  4;16,16,16,16;,
  4;15,15,15,15;,
  4;35,35,35,35;,
  4;20,20,20,20;,
  4;19,19,19,19;,
  4;18,18,18,18;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;38,38,38,38;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;27,27,27;,
  3;27,27,27;,
  3;27,27,27;,
  3;39,39,39;,
  3;39,39,39;,
  3;40,40,40;;
 }
 MeshTextureCoords {
  74;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.166667;0.000000;,
  0.166667;1.000000;,
  0.000000;1.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  0.833333;0.000000;,
  0.833333;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083333;0.000000;,
  0.250000;0.000000;,
  0.416667;0.000000;,
  0.583333;0.000000;,
  0.750000;0.000000;,
  0.916667;0.000000;,
  0.083333;1.000000;,
  0.250000;1.000000;,
  0.416667;1.000000;,
  0.583333;1.000000;,
  0.750000;1.000000;,
  0.916667;1.000000;;
 }
}