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
 229;
 -73.37713;-21.60116;-108.76665;,
 70.83900;-21.60116;-108.76665;,
 70.76633;-5.97249;-161.26529;,
 -73.30428;-5.97249;-161.26529;,
 206.20879;23.90980;-66.53936;,
 206.20879;32.24622;-94.54375;,
 70.76633;-5.97249;-161.26529;,
 178.33057;-31.82638;-83.13220;,
 44.31745;-126.08714;-139.87160;,
 178.33057;-23.48920;-111.13587;,
 44.24440;-110.45857;-192.36981;,
 -208.74661;32.24622;-94.54375;,
 -208.74661;23.90980;-66.53936;,
 -73.30428;-5.97249;-161.26529;,
 -180.86872;-23.48920;-111.13587;,
 -46.78239;-110.45857;-192.36981;,
 -180.86872;-31.82638;-83.13220;,
 -46.85554;-126.08714;-139.87160;,
 -30.67319;-112.41421;61.29490;,
 -47.77311;-19.47854;61.29490;,
 -73.37713;-21.60116;-108.76665;,
 -46.85554;-126.08714;-139.87160;,
 28.13541;-112.41421;61.29490;,
 44.31745;-126.08714;-139.87160;,
 45.23503;-19.47854;61.29490;,
 70.83900;-21.60116;-108.76665;,
 158.84657;-68.09392;-47.77488;,
 158.84657;-100.40718;-29.11919;,
 -161.38440;-100.40718;-29.11919;,
 -161.38440;-68.09392;-47.77488;,
 158.84657;-100.40718;8.19250;,
 -161.38440;-100.40718;8.19250;,
 158.84657;-68.09392;26.84846;,
 -161.38440;-68.09392;26.84846;,
 158.84657;-35.78107;8.19250;,
 -161.38440;-35.78107;8.19250;,
 158.84657;-35.78107;-29.11919;,
 -161.38440;-35.78107;-29.11919;,
 158.84657;-68.09392;-47.77488;,
 -161.38440;-68.09392;-47.77488;,
 158.84657;-68.09392;-10.46312;,
 158.84657;-68.09392;-10.46312;,
 158.84657;-68.09392;-10.46312;,
 158.84657;-68.09392;-10.46312;,
 158.84657;-68.09392;-10.46312;,
 158.84657;-68.09392;-10.46312;,
 -161.38440;-68.09392;-10.46312;,
 -161.38440;-68.09392;-10.46312;,
 -161.38440;-68.09392;-10.46312;,
 -161.38440;-68.09392;-10.46312;,
 -161.38440;-68.09392;-10.46312;,
 -161.38440;-68.09392;-10.46312;,
 57.73170;-10.89013;-191.96625;,
 -60.26970;-10.89013;-191.96625;,
 -73.30428;-5.97249;-161.26529;,
 70.76633;-5.97249;-161.26529;,
 36.00659;-113.99861;-207.96377;,
 44.24440;-110.45857;-192.36981;,
 -38.54460;-113.99861;-207.96377;,
 -46.78239;-110.45857;-192.36981;,
 36.07894;-144.32041;-155.47920;,
 36.00659;-113.99861;-207.96377;,
 44.24440;-110.45857;-192.36981;,
 -38.61713;-144.32041;-155.47920;,
 -38.54460;-113.99861;-207.96377;,
 -46.78239;-110.45857;-192.36981;,
 55.49502;-1.55520;81.95070;,
 -58.03323;-1.55520;81.95070;,
 99.93886;16.17238;54.72099;,
 -102.47710;16.17238;54.72099;,
 -102.47710;16.68108;-52.79197;,
 99.93886;16.68108;-52.79197;,
 69.41607;12.23951;-102.91328;,
 -71.95426;12.23951;-102.91328;,
 -37.15743;-16.26692;95.56241;,
 34.61970;-16.26692;95.56241;,
 63.34948;-155.79121;170.91221;,
 -65.88747;-155.79121;170.91221;,
 -21.81307;-20.55404;146.43013;,
 19.27519;-20.55404;146.43013;,
 -38.24664;-100.36257;189.53079;,
 35.70902;-100.36257;189.53079;,
 -200.10172;-205.03872;152.03142;,
 -195.41671;-200.00777;186.29868;,
 -194.47220;-367.08975;217.88267;,
 -208.09622;-487.72198;327.49849;,
 191.93404;-367.08975;217.88267;,
 205.55835;-487.72198;327.49849;,
 197.56339;-205.03872;152.03142;,
 192.87868;-200.00777;186.29868;,
 -176.31761;-236.28931;252.20328;,
 -178.24776;-387.23204;327.58379;,
 -82.73107;-195.92447;236.55909;,
 -82.90919;-114.77800;193.76653;,
 175.70977;-387.23204;327.58379;,
 173.77954;-236.28931;252.20328;,
 80.37125;-114.77800;193.76653;,
 80.19304;-195.92447;236.55909;,
 199.83672;-376.71734;616.17354;,
 213.92779;-382.83790;601.60890;,
 210.66741;-324.29849;574.79942;,
 195.70089;-302.83848;582.18058;,
 180.93251;-293.63262;563.83912;,
 185.93977;-382.83790;605.01241;,
 208.65401;-531.75518;688.68819;,
 222.01526;-525.04356;668.11114;,
 199.84651;-376.88726;616.25382;,
 194.02743;-525.04356;671.51524;,
 163.17606;-241.03550;207.12596;,
 178.92637;-241.03550;207.12596;,
 163.17606;-240.79952;207.62679;,
 150.72753;-241.03550;207.12596;,
 177.80374;-284.36036;538.11261;,
 150.72973;-151.91460;165.68716;,
 150.72753;-241.03550;207.12596;,
 182.90003;-373.82471;580.01822;,
 177.80374;-284.36036;538.11261;,
 182.90003;-373.82471;580.01822;,
 210.88821;-373.82471;576.61446;,
 178.92401;-182.57967;180.15613;,
 207.53872;-315.02559;549.07296;,
 210.88821;-373.82471;576.61446;,
 207.53872;-315.02559;549.07296;,
 150.72973;-365.54044;274.07505;,
 191.00294;-516.07100;646.64576;,
 191.00294;-516.07100;646.64576;,
 218.99099;-516.07100;643.24312;,
 178.92401;-383.15538;274.07505;,
 218.99099;-516.07100;643.24312;,
 182.90003;-373.82471;580.01822;,
 194.59916;-362.27803;573.10626;,
 194.59916;-362.27803;573.10626;,
 163.17598;-165.45144;172.07453;,
 190.36770;-288.02398;538.32686;,
 190.36770;-288.02398;538.32686;,
 190.36770;-288.02398;538.32686;,
 163.17598;-165.45144;172.07453;,
 163.17606;-383.15538;274.07505;,
 203.35644;-516.04180;645.12940;,
 203.35644;-516.04180;645.12940;,
 203.35644;-516.04180;645.12940;,
 163.17606;-383.15538;274.07505;,
 194.61057;-362.48091;573.20162;,
 194.61057;-362.48091;573.20162;,
 -198.23924;-302.83848;582.18058;,
 -213.20576;-324.29849;574.79942;,
 -216.46575;-382.83790;601.60890;,
 -202.37473;-376.71734;616.17354;,
 -188.47768;-382.83790;605.01241;,
 -183.47043;-293.63262;563.83912;,
 -202.38466;-376.88726;616.25382;,
 -224.55354;-525.04356;668.11114;,
 -211.19197;-531.75518;688.68819;,
 -196.56543;-525.04356;671.51524;,
 -165.71409;-240.79952;207.62679;,
 -181.46435;-241.03550;207.12596;,
 -165.71409;-241.03550;207.12596;,
 -153.26558;-241.03550;207.12596;,
 -185.43810;-373.82471;580.01822;,
 -153.26558;-241.03550;207.12596;,
 -153.26785;-151.91460;165.68716;,
 -180.34152;-284.36036;538.11261;,
 -185.43810;-373.82471;580.01822;,
 -180.34152;-284.36036;538.11261;,
 -210.07632;-315.02559;549.07296;,
 -181.46209;-182.57967;180.15613;,
 -213.42627;-373.82471;576.61446;,
 -210.07632;-315.02559;549.07296;,
 -213.42627;-373.82471;576.61446;,
 -193.54085;-516.07100;646.64576;,
 -153.26785;-365.54044;274.07505;,
 -193.54085;-516.07100;646.64576;,
 -181.46209;-383.15538;274.07505;,
 -221.52928;-516.07100;643.24312;,
 -221.52928;-516.07100;643.24312;,
 -197.13708;-362.27803;573.10626;,
 -185.43810;-373.82471;580.01822;,
 -197.13708;-362.27803;573.10626;,
 -192.90575;-288.02398;538.32686;,
 -165.71393;-165.45144;172.07453;,
 -192.90575;-288.02398;538.32686;,
 -165.71393;-165.45144;172.07453;,
 -192.90575;-288.02398;538.32686;,
 -205.89446;-516.04180;645.12940;,
 -165.71409;-383.15538;274.07505;,
 -205.89446;-516.04180;645.12940;,
 -165.71409;-383.15538;274.07505;,
 -205.89446;-516.04180;645.12940;,
 -197.14882;-362.48091;573.20162;,
 -197.14882;-362.48091;573.20162;,
 -1.32656;-135.66292;108.62681;,
 29.72900;-130.33909;120.33679;,
 46.84124;-236.43506;149.77742;,
 -1.32656;-244.69297;131.61513;,
 42.59250;-117.48548;148.60775;,
 66.79262;-216.49898;193.62530;,
 29.72900;-104.63159;176.87858;,
 46.84124;-196.56302;237.47369;,
 -1.32673;-99.30742;188.58902;,
 -1.32673;-188.30506;255.63584;,
 -32.26724;-104.63159;176.87858;,
 -49.37917;-196.56302;237.47369;,
 -45.13078;-117.48548;148.60775;,
 -69.33076;-216.49898;193.62530;,
 -32.26724;-130.33909;120.33679;,
 -49.37917;-236.43506;149.77742;,
 -1.32656;-117.48548;148.60775;,
 -1.32656;-216.49898;193.62530;,
 111.94490;-3.40210;-104.78152;,
 131.81886;1.28567;-48.84009;,
 -114.48339;-3.40210;-104.78152;,
 -134.35659;1.28567;-48.84009;,
 99.93886;16.58754;-33.00159;,
 -102.47710;16.58754;-33.00159;,
 139.60233;-0.84191;49.11849;,
 50.11134;-11.52039;46.44525;,
 46.68271;-20.17477;46.23890;,
 -49.22092;-20.17477;46.23890;,
 -52.64927;-11.52039;46.44525;,
 -142.14053;-0.84191;49.11849;,
 99.93886;16.19659;49.52418;,
 -102.47710;16.19659;49.52418;,
 48.70935;-45.74593;47.10445;,
 127.31657;-35.06722;49.77786;,
 103.86091;-43.54993;-104.00803;,
 120.47956;-32.93955;-48.18049;,
 -123.01789;-32.93955;-48.18049;,
 -129.85458;-35.06722;49.77786;,
 -51.24748;-45.74593;47.10445;;
 
 181;
 4;0,1,2,3;,
 4;4,5,6,1;,
 4;7,4,1,8;,
 4;9,7,8,10;,
 4;5,9,10,6;,
 4;5,4,7,9;,
 4;11,12,0,13;,
 4;14,11,13,15;,
 4;16,14,15,17;,
 4;12,16,17,0;,
 4;12,11,14,16;,
 4;18,19,20,21;,
 4;22,18,21,23;,
 4;24,22,23,25;,
 4;26,27,28,29;,
 4;27,30,31,28;,
 4;30,32,33,31;,
 4;32,34,35,33;,
 4;34,36,37,35;,
 4;36,38,39,37;,
 3;40,27,26;,
 3;41,30,27;,
 3;42,32,30;,
 3;43,34,32;,
 3;44,36,34;,
 3;45,38,36;,
 3;46,29,28;,
 3;47,28,31;,
 3;48,31,33;,
 3;49,33,35;,
 3;50,35,37;,
 3;51,37,39;,
 4;52,53,54,55;,
 4;56,52,55,57;,
 4;53,58,59,54;,
 4;53,52,56,58;,
 4;60,61,62,8;,
 4;63,60,8,17;,
 4;64,63,17,65;,
 4;64,61,60,63;,
 4;66,67,19,24;,
 4;68,69,67,66;,
 4;70,71,72,73;,
 4;74,75,24,19;,
 4;76,77,18,22;,
 4;78,79,75,74;,
 4;80,78,74,77;,
 4;81,80,77,76;,
 4;79,81,76,75;,
 4;79,78,80,81;,
 4;82,83,74,19;,
 4;84,82,19,18;,
 4;85,84,18,77;,
 4;85,83,82,84;,
 4;86,87,76,22;,
 4;88,86,22,24;,
 4;89,88,24,75;,
 4;89,87,86,88;,
 4;90,91,92,93;,
 4;83,85,91,90;,
 4;85,77,92,91;,
 4;77,74,93,92;,
 4;74,83,90,93;,
 4;94,95,96,97;,
 4;87,89,95,94;,
 4;89,75,96,95;,
 4;75,76,97,96;,
 4;76,87,94,97;,
 4;98,99,100,101;,
 4;98,101,102,103;,
 4;104,105,99,106;,
 4;104,106,103,107;,
 3;108,109,110;,
 3;108,110,111;,
 4;112,113,114,115;,
 4;116,117,103,102;,
 4;118,109,119,120;,
 4;121,122,100,99;,
 4;115,114,123,124;,
 4;117,125,107,103;,
 4;126,127,109,118;,
 4;128,121,99,105;,
 4;129,111,110,130;,
 4;117,131,98,103;,
 4;130,110,109,118;,
 4;131,121,99,98;,
 4;120,119,132,133;,
 4;122,134,101,100;,
 4;135,136,113,112;,
 4;134,116,102,101;,
 4;124,123,137,138;,
 4;125,139,104,107;,
 4;140,141,127,126;,
 4;139,128,105,104;,
 4;118,109,108,142;,
 4;121,143,106,99;,
 4;142,108,111,129;,
 4;143,117,103,106;,
 4;144,145,146,147;,
 4;148,149,144,147;,
 4;150,146,151,152;,
 4;153,148,150,152;,
 3;154,155,156;,
 3;157,154,156;,
 4;158,159,160,161;,
 4;149,148,162,163;,
 4;164,165,155,166;,
 4;146,145,167,168;,
 4;169,170,159,158;,
 4;148,153,171,162;,
 4;166,155,172,173;,
 4;151,146,168,174;,
 4;175,154,157,176;,
 4;148,147,177,162;,
 4;166,155,154,175;,
 4;147,146,168,177;,
 4;178,179,165,164;,
 4;145,144,180,167;,
 4;161,160,181,182;,
 4;144,149,163,180;,
 4;183,184,170,169;,
 4;153,152,185,171;,
 4;173,172,186,187;,
 4;152,151,174,185;,
 4;188,156,155,166;,
 4;146,150,189,168;,
 4;176,157,156,188;,
 4;150,148,162,189;,
 4;190,191,192,193;,
 4;191,194,195,192;,
 4;194,196,197,195;,
 4;196,198,199,197;,
 4;198,200,201,199;,
 4;200,202,203,201;,
 4;202,204,205,203;,
 4;204,190,193,205;,
 3;206,191,190;,
 3;206,194,191;,
 3;206,196,194;,
 3;206,198,196;,
 3;206,200,198;,
 3;206,202,200;,
 3;206,204,202;,
 3;206,190,204;,
 3;207,193,192;,
 3;207,192,195;,
 3;207,195,197;,
 3;207,197,199;,
 3;207,199,201;,
 3;207,201,203;,
 3;207,203,205;,
 3;207,205,193;,
 3;208,72,209;,
 4;208,25,20,210;,
 4;208,210,73,72;,
 3;211,73,210;,
 4;212,209,72,71;,
 4;213,70,73,211;,
 4;212,71,70,213;,
 4;214,66,24,215;,
 3;215,24,216;,
 4;215,216,25,208;,
 3;217,19,218;,
 4;217,218,211,210;,
 3;217,210,20;,
 4;219,218,19,67;,
 4;220,68,66,214;,
 4;220,214,209,212;,
 4;219,67,69,221;,
 4;219,221,213,211;,
 4;221,69,68,220;,
 4;221,220,212,213;,
 4;222,223,214,215;,
 4;224,222,215,208;,
 4;225,224,208,209;,
 4;223,225,209,214;,
 4;223,222,224,225;,
 4;226,227,219,211;,
 4;228,226,211,218;,
 4;227,228,218,219;,
 3;227,226,228;;
 
 MeshMaterialList {
  9;
  181;
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
  2,
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
  1,
  1,
  1,
  1,
  3,
  3,
  3,
  3,
  0,
  0,
  1,
  3,
  0,
  3,
  1,
  3,
  0,
  3,
  0,
  3,
  0,
  3,
  0,
  3,
  1,
  3,
  1,
  3,
  0,
  3,
  0,
  3,
  0,
  3,
  3,
  3,
  3,
  3,
  0,
  0,
  1,
  3,
  0,
  3,
  1,
  3,
  0,
  3,
  0,
  3,
  0,
  3,
  0,
  3,
  1,
  3,
  1,
  3,
  0,
  3,
  0,
  3,
  0,
  3,
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
  1;;
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
  170;
  0.000000;0.958432;0.285322;,
  -0.433938;0.103377;-0.894992;,
  0.622272;-0.750141;-0.223755;,
  -0.244850;-0.190835;0.950595;,
  -0.622272;-0.750141;-0.223756;,
  0.380319;0.886340;0.264118;,
  -0.380319;0.886341;0.264118;,
  0.966529;-0.225559;0.122253;,
  0.000000;-0.997698;0.067812;,
  -0.966528;-0.225560;0.122254;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.499992;-0.866030;,
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.499998;0.866027;,
  0.000000;0.500003;0.866024;,
  0.000000;1.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.987413;-0.158162;,
  -0.905316;-0.120982;-0.407144;,
  0.905316;-0.120982;-0.407145;,
  0.877244;-0.434314;-0.204485;,
  0.000000;-0.650289;0.759687;,
  0.000000;0.996097;-0.088271;,
  0.000000;-0.755297;0.655383;,
  0.000000;0.838046;0.545600;,
  0.000000;0.995637;-0.093313;,
  0.000000;-0.929845;-0.367952;,
  0.000000;0.996467;0.083982;,
  0.000000;-0.318418;0.947950;,
  -0.890512;0.344102;0.297627;,
  0.359618;-0.228451;-0.904702;,
  -0.810671;-0.542363;-0.220579;,
  -0.741677;0.665433;0.084347;,
  -0.359616;-0.228452;-0.904702;,
  0.741679;0.665431;0.084341;,
  0.810671;-0.542363;-0.220580;,
  -0.048275;0.456290;0.888520;,
  0.048275;0.456290;0.888521;,
  0.996243;-0.011460;-0.085840;,
  -0.000000;-0.904609;0.426243;,
  0.994318;-0.020721;-0.104414;,
  -0.996508;0.010277;0.082864;,
  0.000000;-0.904609;0.426243;,
  -0.994147;0.024601;0.105202;,
  0.743598;0.312795;0.590950;,
  0.744831;0.316965;0.587162;,
  -0.674235;0.277584;0.684364;,
  -0.673318;0.281456;0.683685;,
  0.746635;0.644239;0.165807;,
  -0.470949;-0.841416;-0.265003;,
  0.268914;0.917556;0.292877;,
  0.309443;-0.890982;-0.332260;,
  -0.996243;-0.011456;-0.085838;,
  -0.994318;-0.020719;-0.104414;,
  0.996508;0.010275;0.082863;,
  0.994147;0.024601;0.105202;,
  -0.743598;0.312792;0.590952;,
  -0.744822;0.316969;0.587172;,
  0.674228;0.277589;0.684369;,
  0.673315;0.281458;0.683687;,
  -0.746638;0.644236;0.165806;,
  0.470951;-0.841415;-0.265002;,
  -0.268916;0.917555;0.292877;,
  -0.309446;-0.890981;-0.332260;,
  0.000004;0.910330;-0.413884;,
  0.374841;-0.191266;-0.907145;,
  0.904960;0.028150;-0.424565;,
  0.904960;0.338436;0.257891;,
  0.374846;0.557842;0.740474;,
  -0.375827;0.557658;0.740116;,
  -0.904960;0.338435;0.257894;,
  -0.904959;0.028147;-0.424566;,
  0.000002;-0.910325;0.413895;,
  0.331003;0.923270;-0.194961;,
  0.000000;0.213906;-0.976854;,
  -0.331002;0.923271;-0.194956;,
  0.445594;0.878540;-0.172085;,
  -0.445600;0.878537;-0.172087;,
  0.923609;-0.368433;0.105845;,
  -0.923619;-0.368406;0.105853;,
  0.544784;-0.825231;0.149009;,
  -0.544785;-0.825232;0.149005;,
  0.403312;0.785795;0.468898;,
  -0.403312;0.785795;0.468898;,
  -0.929252;0.104767;-0.354280;,
  0.929149;-0.251245;-0.271216;,
  -0.942002;-0.326558;-0.077409;,
  -0.035187;0.026025;0.999042;,
  0.781265;0.130219;-0.610465;,
  0.433938;0.103375;-0.894992;,
  0.901736;-0.414316;-0.123342;,
  0.244850;-0.190835;0.950595;,
  -0.901738;-0.414312;-0.123341;,
  0.000000;0.499997;-0.866027;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.153318;-0.988177;,
  -0.877246;-0.434310;-0.204485;,
  0.000000;-0.865884;-0.500245;,
  0.890513;0.344102;0.297626;,
  0.000000;0.475184;0.879887;,
  -0.999850;-0.008507;-0.015103;,
  0.999850;-0.008509;-0.015110;,
  -0.884723;0.226355;0.407466;,
  0.920042;-0.378763;0.100306;,
  0.896288;0.136941;0.421800;,
  -0.549204;0.682752;0.481897;,
  0.884723;0.226356;0.407467;,
  0.549204;0.682752;0.481897;,
  -0.896288;0.136943;0.421800;,
  -0.920042;-0.378764;0.100304;,
  -0.992686;0.000002;0.120728;,
  0.992686;0.000001;-0.120722;,
  -0.992686;0.000001;0.120727;,
  0.992686;0.000000;-0.120722;,
  0.567989;-0.753400;-0.331327;,
  -0.284082;-0.913722;-0.290534;,
  -0.543899;-0.810858;-0.216061;,
  0.827907;0.553205;0.092385;,
  0.480097;0.839755;0.253612;,
  0.243071;0.924645;0.293170;,
  -0.038808;-0.941447;-0.334919;,
  -0.021056;-0.941677;-0.335858;,
  -0.042168;-0.941445;-0.334520;,
  0.537991;0.814346;0.217731;,
  -0.290663;0.897199;0.332488;,
  -0.561708;0.757855;0.331874;,
  0.992686;-0.000000;0.120727;,
  -0.992685;-0.000005;-0.120737;,
  0.992686;0.000001;0.120725;,
  -0.992687;0.000003;-0.120719;,
  -0.567991;-0.753399;-0.331325;,
  0.284080;-0.913722;-0.290534;,
  0.543897;-0.810859;-0.216062;,
  -0.827910;0.553202;0.092369;,
  -0.480097;0.839754;0.253612;,
  -0.243065;0.924646;0.293169;,
  0.038840;-0.941447;-0.334915;,
  0.021056;-0.941677;-0.335858;,
  0.042205;-0.941445;-0.334515;,
  -0.537996;0.814343;0.217731;,
  0.290660;0.897200;0.332488;,
  0.561703;0.757859;0.331872;,
  -0.375820;-0.191117;-0.906771;,
  0.000000;0.910328;-0.413888;,
  0.000000;0.910324;-0.413897;,
  -0.000004;0.910326;-0.413893;,
  0.000004;0.910326;-0.413893;,
  0.000000;0.910324;-0.413897;,
  0.000000;0.910328;-0.413888;,
  -0.000004;0.910330;-0.413884;,
  0.000000;-0.910326;0.413893;,
  -0.000000;-0.910328;0.413887;,
  -0.000006;-0.910326;0.413892;,
  0.000006;-0.910326;0.413892;,
  0.000000;-0.910326;0.413893;,
  -0.000002;-0.910325;0.413895;,
  0.000000;0.118597;-0.992942;,
  0.000000;0.999989;0.004727;,
  0.708695;-0.691574;0.139559;,
  -0.604035;-0.769969;0.205646;,
  -0.398105;-0.914630;0.070458;,
  0.410898;0.911668;-0.004966;,
  -0.410901;0.911667;-0.004967;,
  0.000000;0.999989;0.004659;,
  0.000000;0.999989;0.004737;,
  0.942000;-0.326564;-0.077408;,
  0.215784;-0.975937;0.031365;,
  0.035187;0.026025;0.999042;,
  -0.135582;-0.990282;-0.030972;;
  181;
  4;0,0,0,0;,
  4;6,6,6,6;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;89,89,89,89;,
  4;90,90,90,90;,
  4;5,5,5,5;,
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;91,91,91,91;,
  4;92,92,92,92;,
  4;9,9,9,9;,
  4;8,8,8,8;,
  4;7,7,7,7;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;93,93,93,93;,
  3;10,10,10;,
  3;10,10,10;,
  3;10,10,10;,
  3;10,10,10;,
  3;10,10,10;,
  3;94,94,94;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;95,95,95;,
  4;17,17,17,17;,
  4;19,19,19,19;,
  4;18,18,18,18;,
  4;96,96,96,96;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;97,97,97,97;,
  4;98,98,98,98;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;22,22,22,22;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;27,27,27,27;,
  4;29,29,29,29;,
  4;28,28,28,28;,
  4;99,99,99,99;,
  4;100,100,100,100;,
  4;32,32,32,32;,
  4;33,33,33,33;,
  4;35,35,35,35;,
  4;101,101,101,101;,
  4;31,31,31,31;,
  4;30,30,30,30;,
  4;34,34,34,34;,
  4;102,102,102,102;,
  4;36,36,36,36;,
  4;103,103,103,103;,
  4;104,104,104,104;,
  4;105,105,105,105;,
  4;106,106,106,106;,
  4;37,37,37,37;,
  4;107,107,107,107;,
  4;108,108,108,108;,
  4;109,109,109,109;,
  4;110,110,110,110;,
  4;44,44,44,44;,
  4;46,46,46,46;,
  4;45,45,45,45;,
  4;47,47,47,47;,
  3;39,39,39;,
  3;42,42,42;,
  4;41,41,41,41;,
  4;111,111,111,111;,
  4;38,38,38,38;,
  4;112,112,112,112;,
  4;43,43,43,43;,
  4;113,113,113,113;,
  4;40,40,40,40;,
  4;114,114,114,114;,
  4;51,51,51,51;,
  4;115,115,115,115;,
  4;116,116,116,116;,
  4;117,117,117,117;,
  4;48,48,48,48;,
  4;118,118,118,118;,
  4;119,119,119,119;,
  4;120,120,120,120;,
  4;49,49,49,49;,
  4;121,121,121,121;,
  4;122,122,122,122;,
  4;123,123,123,123;,
  4;50,50,50,50;,
  4;124,124,124,124;,
  4;125,125,125,125;,
  4;126,126,126,126;,
  4;56,56,56,56;,
  4;58,58,58,58;,
  4;57,57,57,57;,
  4;59,59,59,59;,
  3;42,42,42;,
  3;42,42,42;,
  4;54,54,54,54;,
  4;127,127,127,127;,
  4;52,52,52,52;,
  4;128,128,128,128;,
  4;55,55,55,55;,
  4;129,129,129,129;,
  4;53,53,53,53;,
  4;130,130,130,130;,
  4;63,63,63,63;,
  4;131,131,131,131;,
  4;132,132,132,132;,
  4;133,133,133,133;,
  4;60,60,60,60;,
  4;134,134,134,134;,
  4;135,135,135,135;,
  4;136,136,136,136;,
  4;61,61,61,61;,
  4;137,137,137,137;,
  4;138,138,138,138;,
  4;139,139,139,139;,
  4;62,62,62,62;,
  4;140,140,140,140;,
  4;141,141,141,141;,
  4;142,142,142,142;,
  4;65,65,65,65;,
  4;66,66,66,66;,
  4;67,67,67,67;,
  4;68,68,68,68;,
  4;69,69,69,69;,
  4;70,70,70,70;,
  4;71,71,71,71;,
  4;143,143,143,143;,
  3;64,64,64;,
  3;144,144,144;,
  3;145,145,145;,
  3;146,146,146;,
  3;147,147,147;,
  3;148,148,148;,
  3;149,149,149;,
  3;150,150,150;,
  3;72,72,72;,
  3;151,151,151;,
  3;152,152,152;,
  3;153,153,153;,
  3;154,154,154;,
  3;152,152,152;,
  3;155,155,155;,
  3;156,156,156;,
  3;73,73,73;,
  4;74,74,74,74;,
  4;157,157,157,157;,
  3;75,75,75;,
  4;76,76,76,76;,
  4;77,77,77,77;,
  4;158,158,158,158;,
  4;80,80,80,80;,
  3;78,78,78;,
  4;159,159,159,159;,
  3;79,79,79;,
  4;160,160,160,160;,
  3;161,161,161;,
  4;81,81,81,81;,
  4;82,82,82,82;,
  4;162,162,162,162;,
  4;83,83,83,83;,
  4;163,163,163,163;,
  4;164,164,164,164;,
  4;165,165,165,165;,
  4;87,87,87,87;,
  4;84,84,84,84;,
  4;85,85,85,85;,
  4;166,166,166,166;,
  4;167,167,167,167;,
  4;86,86,86,86;,
  4;88,88,88,88;,
  4;168,168,168,168;,
  3;169,169,169;;
 }
 MeshTextureCoords {
  229;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
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
  0.916667;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  -1.558860;-0.600590;,
  -1.561780;-0.555500;,
  -1.356640;-0.557270;,
  -1.299760;-0.602360;,
  -1.244050;-0.557270;,
  -1.557070;-0.555500;,
  -2.104210;-0.600280;,
  -2.061980;-0.555190;,
  -1.559460;-0.600590;,
  -2.057280;-0.555190;,
  0.233640;-0.994150;,
  0.234510;-0.994150;,
  0.233340;-0.994170;,
  0.232880;-0.994140;,
  0.143140;-0.644350;,
  0.764840;0.375140;,
  0.544840;0.377170;,
  -0.078290;-0.644350;,
  -1.182170;-0.495200;,
  -1.496950;-0.495200;,
  0.124220;-2.130300;,
  0.233950;-0.733570;,
  0.124090;-1.867100;,
  -1.501650;-0.495200;,
  -1.294770;-0.495200;,
  0.193190;0.377530;,
  -0.430360;-0.644350;,
  -1.997440;-0.495200;,
  0.124550;-2.767020;,
  0.235240;-1.630110;,
  -2.002140;-0.495200;,
  0.116440;-2.130290;,
  0.119940;-2.078610;,
  -1.458390;-0.495200;,
  0.232960;-0.656900;,
  0.119770;-1.746240;,
  -1.197140;-0.495200;,
  0.170180;-0.644350;,
  0.767440;0.375140;,
  0.229290;0.377530;,
  -0.394180;-0.644350;,
  -1.999410;-0.495200;,
  0.120300;-2.766880;,
  0.234400;-1.630110;,
  0.119940;-2.079520;,
  -1.459110;-0.495200;,
  -1.204270;-0.602360;,
  -1.255900;-0.557270;,
  -1.461040;-0.555500;,
  -1.463370;-0.600590;,
  -1.465740;-0.555500;,
  -1.152710;-0.557270;,
  -1.463970;-0.600590;,
  -1.961240;-0.555190;,
  -2.008720;-0.600280;,
  -1.965940;-0.555190;,
  0.767740;-0.994000;,
  0.766560;-0.993980;,
  0.767440;-0.993990;,
  0.768200;-0.993990;,
  -1.666980;-0.644350;,
  -1.043840;0.377170;,
  -0.823850;0.375140;,
  -1.445540;-0.644350;,
  -1.405610;-0.495200;,
  -1.090830;-0.495200;,
  0.876970;-1.866930;,
  0.767120;-0.733400;,
  0.876830;-2.130130;,
  -1.194030;-0.495200;,
  -1.400910;-0.495200;,
  -2.019050;-0.644350;,
  -1.395500;0.377530;,
  -1.906100;-0.495200;,
  0.765840;-1.629940;,
  0.876490;-2.766850;,
  -1.901400;-0.495200;,
  0.881110;-2.078450;,
  0.884610;-2.130140;,
  -1.362910;-0.495200;,
  0.881290;-1.746070;,
  0.768110;-0.656740;,
  -1.101650;-0.495200;,
  -0.893460;0.375140;,
  -1.490710;-0.644350;,
  -2.055080;-0.644350;,
  -1.431600;0.377530;,
  -1.903920;-0.495200;,
  0.766670;-1.629940;,
  0.880750;-2.766720;,
  0.881110;-2.079360;,
  -1.363620;-0.495200;,
  1.979820;2.329620;,
  2.199610;2.323060;,
  2.320450;3.099660;,
  1.979550;3.109840;,
  2.290660;2.307070;,
  2.461670;3.074850;,
  2.199630;2.291010;,
  2.320470;3.049950;,
  1.979840;2.284300;,
  1.979580;3.039540;,
  1.760040;2.290860;,
  1.638670;3.049720;,
  1.669000;2.306850;,
  1.497460;3.074520;,
  1.760030;2.322910;,
  1.638660;3.099420;,
  1.979830;2.306960;,
  1.979560;3.074690;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;;
 }
}