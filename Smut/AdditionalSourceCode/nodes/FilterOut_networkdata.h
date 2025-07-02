namespace project
{

struct FilterOut_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "FilterOut";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "288.nT6K8CV0.TKB.XFD1PBHKaS.OgDKDY26BHliL.HEjx5eFAUqG3D4WAfrkD2KqSlPR+vJ.rB.s.PlmsXKlhH+qaSP1xUnO4kZuNylJWG4P6bG7HUBPN5ZRTAxGYxS9FfsCQtRsCiNf9Imj0rUNSexegml1MUH7WayHsf7qswWKoDjOSbipfcTZk.Pd9RWI75VTheuFRjIN4qZQHuogQN4c.sfQiGPNfXnIxCoZWCYg40hTMTK3Wd7jBtcg7niZYfi7FFr3QiGLfVLMghfsT7vR4rES0WihlGxQVyB2n6ZRz.xyTt0xeAHvHHBwcf7x.W4LaFX9fco6XrbljqfB..WzgLs2gJbFrhc7C.Dxfp+.CCD6NsP3RZg2H.ajb.MDgEE";
	}
};
}

