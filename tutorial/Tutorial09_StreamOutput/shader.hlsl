// HLSL model shader


// VERTEX SHADER

cbuffer Settings : register(b0)
{
	float4x4 wvpMatrix;
};

struct InputVS
{
	float3 position : POSITION;
};

struct OutputVS
{
	float4 position : SV_Position;
};

OutputVS VS(InputVS inp)
{
	OutputVS outp;
	outp.position = mul(wvpMatrix, float4(inp.position, 1));
	return outp;
}


// GEOMETRY SHADER

[maxvertexcount(9)]
void GS(triangle OutputVS inp[3], inout TriangleStream<OutputVS> stream)
{
	OutputVS outp;
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			outp = inp[j];
			outp.position.x += (float(i) - 1.0)*4.0;
			outp.position.w = 7.0;
			stream.Append(outp);
		}
		
		stream.RestartStrip();
	}
}


// PIXEL SHADER

float4 PS(OutputVS inp) : SV_Target
{
	return float4(0, 1, 0, 1);
}



