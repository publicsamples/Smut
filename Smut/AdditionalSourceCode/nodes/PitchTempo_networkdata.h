namespace project
{

struct PitchTempo_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "PitchTempo";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "220.nT6K8CFZ.ToA.HEinHBLssJ.XCVFiXsYqJ1AAwlozpNgGQcKtPpjBJbYhsk2zoe.+SmCNhdwUTXgDPP4.ECPokfMIgTLAyvgia7ZLV8WF6Y2vQlQ00hQrI2rB70h28R.ztgWdZQzuZojcdZ3uFyTnX+Z77AUaA5YSl4IBmJ1g.z2K3hpOgRnzln+AaxX23JVD8p1CxbdbPlGPmigCcZZHXpYiYGP+hGPzKQD9X1KADAHPXRm2MiSDgCykAVF7OtiI0bk.73BIF+qFBX+Pvu5v.v7h6vBiPWHUbVDE.";
	}
};
}

