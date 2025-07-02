namespace project
{

struct bank_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "bank";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "136.nT6K8CBn8O..BhDGd.VPaCvOnrZIsV7FYiptQzd1.m+2QDx2kvgfTBk7A7eWqOkI673+t.nxjFekP3QTmKadP7skILUqaKeKyREvm7ximlerTg.7JBaf3WpkZkHfe4lqU.tgDBOqsbRyyBe3vKKGtxlAjFfOwBDdklcdpQv..DEBX9TBibF3n.";
	}
};
}

