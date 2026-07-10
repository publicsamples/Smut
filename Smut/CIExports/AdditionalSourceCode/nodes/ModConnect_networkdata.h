namespace project
{

struct ModConnect_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "ModConnect";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "310.nT6K8C1JDTVB.HQSrPBHMha.GXzne1WeiJ1SKDJ1VcY.Oor.3qM1D.fjDHNQhOwfoTfSqoASiiiFigPqQywQCAIyD7ytP2y2wmixjoAHLrAnYa83HWt32T9Gsb.qo0XMlya4O+gxDnKZ4+ZP+jvRN7XI9axNvtHitGU0xHqTncDLTtr.n4TWUwTWIjOHo7MzwQnKsEn4CQN558nDCYgl8jCoZprrLzD5tpuijQoFB8GS9yJflJrfBMg3cIhMTLCnwkzXQTfBLpTab.H..pxcPct9fno1dt5jrYZreFDAv8zrSklmcMzz6DCwHiGrFIxANPOUGTEx2lgT.FfjbFdtEBtDn.YwaKEQNLyvwgILwjDPgtPCsc9.cDwYMdtt4e6PRDxhxubb3Lea2sxH1QyXloqCnh.7UA";
	}
};
}

