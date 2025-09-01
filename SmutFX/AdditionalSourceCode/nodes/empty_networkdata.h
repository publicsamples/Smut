namespace project
{

struct empty_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "empty";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "133.nT6K8CxnkO..RgrFa.WZazgLoVHKBIPt7a2b6.jATjPUUKDKEDJ8C7eGqstjbd7eG.TWRiqPG7HpykLOCuwxjUh0FK61tPCvmz4wi2dkHBfWQVCDuJoRp1xbrp3DPG7KVaSXdJ6QypnT3ulYQQBveHwA+BdaZ0HA.LEBX+rEbGl0RxRsG.";
	}
};
}

