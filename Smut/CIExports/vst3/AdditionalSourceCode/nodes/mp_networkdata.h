namespace project
{

struct mp_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "mp";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "325.nT6K8CVNAzcB.XbT5PBLIaa.i15DAMQ0.J341RnEisZYOH0XHm.sqWAEB0WMpVBikofK.3B.v.P7g5D3U8VjxtpC2rJjCFilx7hUphuGDksXKFiXUXzMk9EcRhOrZDIMqhQFqdmRRbBs0ZlOnS.lR+coV1UphQVbolhx3lUa9b1SYLPgtNBZIcnqeXDhGX0nuqjQFzhSdMT5OCH3M3rL4uEksT73vHzHn2MIf17ukhOEDFAa4vPOg50WftIGVc2VqWQeGnMIMI5DFcOjCgwC18eT8BdDkgiFNVn34o.FKXOd77rXLAqV4XbZvAnM+oPOcQ3De+nBe.BHBZLtd3.2XZrCAkL9WxBjGJqQ2Qglg2.4izywaUZw.kzBywjrstn53XcvCwcLsF3H.utvXNXTCVODH8CQ+pEgqZtPA1vkU34PnVALJ.";
	}
};
}

