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
 104;
 -8.31841;24.80580;-114.80122;,
 55.95966;8.91758;-114.61382;,
 23.61293;-202.38594;-75.95918;,
 -8.85367;-187.30828;-76.17427;,
 56.24051;12.55961;98.04412;,
 -8.03712;28.44757;97.85705;,
 -8.66525;-184.86436;66.51726;,
 23.80144;-199.94219;66.73248;,
 -8.03712;28.44757;97.85705;,
 -8.31841;24.80580;-114.80122;,
 -8.85367;-187.30828;-76.17427;,
 -8.66525;-184.86436;66.51726;,
 -8.85367;-187.30828;-76.17427;,
 23.61293;-202.38594;-75.95918;,
 23.80144;-199.94219;66.73248;,
 40.98146;52.22800;61.68280;,
 9.15875;67.28896;61.46699;,
 56.24051;12.55961;98.04412;,
 40.79503;49.80876;-79.59241;,
 55.95966;8.91758;-114.61382;,
 8.97178;64.86956;-79.80772;,
 -8.31841;24.80580;-114.80122;,
 68.85540;-0.23531;79.88369;,
 68.62301;-3.24757;-96.05957;,
 55.95966;8.91758;-114.61382;,
 64.83874;-154.36875;53.57647;,
 64.68228;-156.39036;-64.47935;,
 23.61293;-202.38594;-75.95918;,
 107.56459;-4.38838;-96.09141;,
 107.79708;-1.37556;79.85169;,
 114.90777;-47.14299;69.92387;,
 114.70364;-49.78967;-84.62105;,
 85.62087;5.06245;-96.22459;,
 85.85364;8.07601;79.71887;,
 75.65263;-58.11097;70.93846;,
 75.44660;-60.78424;-85.15598;,
 264.61458;-629.86476;50.99282;,
 236.32889;-638.74327;81.02733;,
 224.55730;-643.14317;51.27307;,
 264.67051;-629.14142;93.18752;,
 292.97774;-619.96358;80.63084;,
 304.67081;-616.58565;50.71242;,
 292.89942;-620.98663;20.95777;,
 264.55848;-630.58604;8.79726;,
 236.24954;-639.76466;21.35418;,
 75.07351;-58.28039;41.45469;,
 35.01640;-71.55980;41.73494;,
 46.78843;-67.15947;71.48917;,
 75.12932;-57.55780;83.64941;,
 103.43781;-48.38124;71.09270;,
 115.13034;-45.00209;41.17421;,
 103.35901;-49.40360;11.41966;,
 75.01768;-59.00329;-0.74085;,
 46.70941;-68.18133;11.81621;,
 264.50118;-631.33048;-34.62571;,
 236.21546;-640.20978;-4.59070;,
 224.44431;-644.60919;-34.34507;,
 264.55713;-630.60772;7.56953;,
 292.86543;-621.43028;-4.98704;,
 304.55760;-618.05157;-34.90586;,
 292.78645;-622.45255;-64.66043;,
 264.44546;-632.05284;-76.82124;,
 236.13670;-641.23145;-64.26428;,
 74.96068;-59.74704;-44.16336;,
 34.90280;-73.02590;-43.88313;,
 46.67513;-68.62607;-14.12883;,
 75.01611;-59.02478;-1.96851;,
 103.32478;-49.84760;-14.52534;,
 115.01696;-46.46899;-44.44373;,
 103.24575;-50.86939;-74.19902;,
 74.90468;-60.46973;-86.35877;,
 46.59649;-69.64777;-73.80198;,
 202.72586;-537.40987;79.33647;,
 191.00991;-541.97677;49.58493;,
 202.72586;-537.40987;79.33647;,
 191.00991;-541.97677;49.58493;,
 230.93396;-527.40577;91.48990;,
 230.93396;-527.40577;91.48990;,
 259.10852;-517.82442;78.92640;,
 259.10852;-517.82442;78.92640;,
 270.74600;-514.28018;49.00513;,
 270.74600;-514.28018;49.00513;,
 259.02996;-518.84659;19.25325;,
 259.02996;-518.84659;19.25325;,
 230.82224;-528.85069;7.09941;,
 230.82224;-528.85069;7.09941;,
 202.64722;-538.43165;19.66312;,
 202.64722;-538.43165;19.66312;,
 202.61304;-538.87647;-6.28172;,
 190.89657;-543.44268;-36.03308;,
 202.61304;-538.87647;-6.28172;,
 190.89657;-543.44268;-36.03308;,
 230.82110;-528.87198;5.87202;,
 230.82110;-528.87198;5.87202;,
 258.99541;-519.29083;-6.69153;,
 258.99541;-519.29083;-6.69153;,
 270.63279;-515.74639;-36.61292;,
 270.63279;-515.74639;-36.61292;,
 258.91687;-520.31280;-66.36502;,
 258.91687;-520.31280;-66.36502;,
 230.70948;-530.31680;-78.51873;,
 230.70948;-530.31680;-78.51873;,
 202.53416;-539.89766;-65.95496;,
 202.53416;-539.89766;-65.95496;;
 
 86;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,11;,
 4;15,16,8,17;,
 4;18,15,17,19;,
 4;20,18,19,21;,
 4;16,20,21,8;,
 4;16,15,18,20;,
 4;22,23,24,17;,
 4;25,22,17,14;,
 4;26,25,14,27;,
 4;23,26,27,24;,
 4;28,29,30,31;,
 4;32,23,22,33;,
 4;32,33,29,28;,
 4;33,22,25,34;,
 4;33,34,30,29;,
 4;34,25,26,35;,
 4;34,35,31,30;,
 4;35,26,23,32;,
 4;35,32,28,31;,
 3;36,37,38;,
 3;36,39,37;,
 3;36,40,39;,
 3;36,41,40;,
 3;36,42,41;,
 3;36,43,42;,
 3;36,44,43;,
 3;36,38,44;,
 3;45,46,47;,
 3;45,47,48;,
 3;45,48,49;,
 3;45,49,50;,
 3;45,50,51;,
 3;45,51,52;,
 3;45,52,53;,
 3;45,53,46;,
 3;54,55,56;,
 3;54,57,55;,
 3;54,58,57;,
 3;54,59,58;,
 3;54,60,59;,
 3;54,61,60;,
 3;54,62,61;,
 3;54,56,62;,
 3;63,64,65;,
 3;63,65,66;,
 3;63,66,67;,
 3;63,67,68;,
 3;63,68,69;,
 3;63,69,70;,
 3;63,70,71;,
 3;63,71,64;,
 4;72,47,46,73;,
 4;74,75,38,37;,
 4;76,48,47,72;,
 4;77,74,37,39;,
 4;78,49,48,76;,
 4;79,77,39,40;,
 4;80,50,49,78;,
 4;81,79,40,41;,
 4;82,51,50,80;,
 4;83,81,41,42;,
 4;84,52,51,82;,
 4;85,83,42,43;,
 4;86,53,52,84;,
 4;87,85,43,44;,
 4;73,46,53,86;,
 4;75,87,44,38;,
 4;88,65,64,89;,
 4;90,91,56,55;,
 4;92,66,65,88;,
 4;93,90,55,57;,
 4;94,67,66,92;,
 4;95,93,57,58;,
 4;96,68,67,94;,
 4;97,95,58,59;,
 4;98,69,68,96;,
 4;99,97,59,60;,
 4;100,70,69,98;,
 4;101,99,60,61;,
 4;102,71,70,100;,
 4;103,101,61,62;,
 4;89,64,71,102;,
 4;91,103,62,56;;
 
 MeshMaterialList {
  9;
  86;
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
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
  2,
  7,
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
  86;
  -0.056630;-0.173886;-0.983136;,
  -0.054022;-0.140120;0.988660;,
  0.221456;0.622281;-0.750815;,
  0.935526;0.353184;-0.007283;,
  0.223418;0.647613;0.728479;,
  0.702656;0.711409;-0.013110;,
  0.744583;-0.667449;0.010445;,
  0.603369;-0.187168;0.775187;,
  0.988007;0.154359;-0.003949;,
  -0.439300;0.898219;-0.014801;,
  0.993736;-0.111751;0.000599;,
  -0.015346;-0.154488;0.987875;,
  0.314709;-0.949056;0.015834;,
  0.314727;-0.949050;0.015852;,
  0.314734;-0.949048;0.015852;,
  0.314731;-0.949048;0.015855;,
  0.314732;-0.949048;0.015860;,
  0.314679;-0.949067;0.015805;,
  0.314722;-0.949052;0.015805;,
  -0.314732;0.949049;-0.015833;,
  -0.314735;0.949048;-0.015836;,
  -0.314677;0.949067;-0.015837;,
  -0.314710;0.949056;-0.015802;,
  -0.314710;0.949055;-0.015887;,
  -0.314668;0.949070;-0.015843;,
  -0.314726;0.949050;-0.015843;,
  0.314719;-0.949053;0.015819;,
  0.314738;-0.949047;0.015839;,
  0.314706;-0.949057;0.015839;,
  0.314726;-0.949051;0.015818;,
  0.314726;-0.949050;0.015865;,
  0.314694;-0.949061;0.015832;,
  0.314734;-0.949048;0.015832;,
  -0.314714;0.949055;-0.015821;,
  -0.314724;0.949051;-0.015832;,
  -0.314692;0.949062;-0.015832;,
  -0.314709;0.949057;-0.015814;,
  -0.314709;0.949056;-0.015854;,
  -0.314693;0.949061;-0.015837;,
  -0.314725;0.949051;-0.015837;,
  -0.876429;-0.284142;0.388761;,
  -0.362005;-0.104586;0.926290;,
  0.364454;0.136228;0.921203;,
  0.877442;0.297248;0.376484;,
  0.876432;0.284144;-0.388752;,
  0.362016;0.104590;-0.926286;,
  -0.364458;-0.136228;-0.921202;,
  -0.876427;-0.284142;0.388767;,
  -0.362010;-0.104588;0.926288;,
  0.364455;0.136229;0.921202;,
  0.877444;0.297249;0.376476;,
  0.876437;0.284146;-0.388739;,
  0.362007;0.104587;-0.926290;,
  -0.364454;-0.136227;-0.921203;,
  -0.999995;0.002757;0.001274;,
  -0.421235;-0.906809;0.016087;,
  -0.916328;0.400388;-0.005644;,
  0.427815;0.903724;-0.016042;,
  0.601336;-0.213629;-0.769908;,
  0.395605;0.918277;-0.016249;,
  0.011139;-0.161345;0.986835;,
  0.269449;-0.962880;0.016134;,
  -0.017980;-0.188221;-0.981962;,
  0.008550;-0.195043;-0.980757;,
  0.314709;-0.949056;0.015818;,
  -0.314732;0.949049;-0.015837;,
  0.314719;-0.949053;0.015848;,
  -0.314715;0.949054;-0.015848;,
  -0.876432;-0.284144;0.388753;,
  -0.362000;-0.104586;0.926292;,
  0.364458;0.136228;0.921202;,
  0.877442;0.297243;0.376485;,
  0.876435;0.284139;-0.388750;,
  0.362019;0.104588;-0.926285;,
  -0.364451;-0.136228;-0.921204;,
  -0.877442;-0.297248;-0.376484;,
  -0.877446;-0.297247;-0.376474;,
  -0.876433;-0.284144;0.388750;,
  -0.362004;-0.104585;0.926291;,
  0.364454;0.136227;0.921203;,
  0.877446;0.297247;0.376474;,
  0.876437;0.284141;-0.388745;,
  0.362022;0.104590;-0.926284;,
  -0.364454;-0.136224;-0.921204;,
  -0.877438;-0.297247;-0.376493;,
  -0.877446;-0.297248;-0.376473;;
  86;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;54,54,54,54;,
  4;55,55,55,55;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;56,56,56,56;,
  4;57,57,57,57;,
  4;5,5,5,5;,
  4;7,7,7,7;,
  4;6,6,6,6;,
  4;58,58,58,58;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;59,59,59,59;,
  4;11,11,11,11;,
  4;60,60,60,60;,
  4;10,10,10,10;,
  4;61,61,61,61;,
  4;62,62,62,62;,
  4;63,63,63,63;,
  3;12,12,12;,
  3;13,13,13;,
  3;14,14,14;,
  3;15,15,15;,
  3;16,16,16;,
  3;17,17,17;,
  3;18,18,18;,
  3;64,64,64;,
  3;19,19,19;,
  3;20,20,20;,
  3;21,21,21;,
  3;22,22,22;,
  3;23,23,23;,
  3;24,24,24;,
  3;25,25,25;,
  3;65,65,65;,
  3;26,26,26;,
  3;27,27,27;,
  3;28,28,28;,
  3;29,29,29;,
  3;30,30,30;,
  3;31,31,31;,
  3;32,32,32;,
  3;66,66,66;,
  3;33,33,33;,
  3;34,34,34;,
  3;35,35,35;,
  3;36,36,36;,
  3;37,37,37;,
  3;38,38,38;,
  3;39,39,39;,
  3;67,67,67;,
  4;40,40,40,40;,
  4;68,68,68,68;,
  4;41,41,41,41;,
  4;69,69,69,69;,
  4;42,42,42,42;,
  4;70,70,70,70;,
  4;43,43,43,43;,
  4;71,71,71,71;,
  4;44,44,44,44;,
  4;72,72,72,72;,
  4;45,45,45,45;,
  4;73,73,73,73;,
  4;46,46,46,46;,
  4;74,74,74,74;,
  4;75,75,75,75;,
  4;76,76,76,76;,
  4;47,47,47,47;,
  4;77,77,77,77;,
  4;48,48,48,48;,
  4;78,78,78,78;,
  4;49,49,49,49;,
  4;79,79,79,79;,
  4;50,50,50,50;,
  4;80,80,80,80;,
  4;51,51,51,51;,
  4;81,81,81,81;,
  4;52,52,52,52;,
  4;82,82,82,82;,
  4;53,53,53,53;,
  4;83,83,83,83;,
  4;84,84,84,84;,
  4;85,85,85,85;;
 }
 MeshTextureCoords {
  104;
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
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  2.190250;-2.161110;,
  2.271300;-2.143860;,
  2.190240;-2.136760;,
  2.304890;-2.161070;,
  2.271320;-2.178300;,
  2.190260;-2.185460;,
  2.109200;-2.178360;,
  2.075620;-2.161150;,
  2.109190;-2.143920;,
  1.897060;0.234680;,
  1.921120;0.304380;,
  1.958880;0.283960;,
  1.960430;0.234680;,
  1.924860;0.185400;,
  1.873000;0.164990;,
  1.835240;0.185400;,
  1.833690;0.234680;,
  1.869260;0.283960;,
  1.797610;-2.161240;,
  1.878670;-2.144000;,
  1.797610;-2.136890;,
  1.912250;-2.161210;,
  1.878680;-2.178440;,
  1.797620;-2.185600;,
  1.716560;-2.178490;,
  1.682980;-2.161280;,
  1.716550;-2.144050;,
  1.679990;0.234680;,
  1.704050;0.304380;,
  1.741820;0.283960;,
  1.743370;0.234680;,
  1.707800;0.185400;,
  1.655940;0.164990;,
  1.618170;0.185400;,
  1.616620;0.234680;,
  1.652190;0.283960;,
  2.458790;-0.178380;,
  2.421200;-0.158130;,
  2.271210;-1.860450;,
  2.190150;-1.853810;,
  2.459920;-0.227270;,
  2.304790;-1.876530;,
  2.423910;-0.276150;,
  2.271220;-1.892630;,
  2.371880;-0.296400;,
  2.190160;-1.899330;,
  2.334290;-0.276150;,
  2.109100;-1.892690;,
  2.333170;-0.227270;,
  2.075520;-1.876610;,
  2.369170;-0.178380;,
  2.109090;-1.860510;,
  2.241730;-0.178380;,
  2.204140;-0.158130;,
  1.878570;-1.860590;,
  1.797510;-1.853950;,
  2.242850;-0.227270;,
  1.912150;-1.876670;,
  2.206850;-0.276150;,
  1.878580;-1.892770;,
  2.154810;-0.296400;,
  1.797520;-1.899460;,
  2.117230;-0.276150;,
  1.716460;-1.892820;,
  2.116100;-0.227270;,
  1.682880;-1.876740;,
  2.152100;-0.178380;,
  1.716450;-1.860640;;
 }
}