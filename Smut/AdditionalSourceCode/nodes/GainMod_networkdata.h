namespace project
{

struct GainMod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "GainMod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "468.nT6K8CFaDTkC.XyT+PBDqi9UMYOhr4mvGtiDSff6A3meHNHmt45OL...pI+i6PFnjL0L.PC.0.vVq0gf54JZBeoewDrpmuyzM8+pqvqBe9kc0HGrhUkN11DpQetkDqSfCXUJVfV0go+4gWBUEjHSTLiUmbdzmD0Qh8b9jKPgQN80lXywic3APrptAspz1D9vrd1Y93dV.l0WTGLhUevsaTzmMnXQ5g1RYIlE.qxJzNSi4UeVdXmYyPG4T84vrASEE3hsl+BJk9DlQ2h8SnlOyL8HhTfBIxATUU5K47LIO2hEPqljd3.xiIpFZBncix3EumDl6FfTztnF1G4r3ERFvIj9NyeNIHduFJ.UfFbKxTy.XV.Ar.J.vH.PTLY4A.l7.n.Up4XS.YriHxVTlwxzzNxQQLnGnf.YlzwEbQTikrWl0LmHzD1DwzZcEYMaAHLGH2l3.MxQIYycElFQRi4XdATFpVHLPAkcSHqY3ENAA4nxahgqgZ5tB.MWY5C+jkL.D.POW4OmBsoC1Y0fRvhu7vJgcmtKpMLEdFvRymsxFLRKAe04kvjkGrDrSkkKXV2Ps9rCRRPEl42DzwbzCeqLvoMiUMnCr3ElaJPYvLfY2.PdC3iG";
	}
};
}

