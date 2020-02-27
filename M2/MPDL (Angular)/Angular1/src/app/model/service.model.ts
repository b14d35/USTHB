export class Service {
  private $id: number;
  private $prix: number;
  private $type: string;

  constructor(id: number, prix: number, type: string) {
    this.$id = id;
    this.$prix = prix;
    this.$type = type;
  }

  public get id(): number {
    return this.$id;
  }

  public get prix(): number {
    return this.$prix;
  }

  public get type(): string {
    return this.$type;
  }

  public getInfos(): string {
    return this.$type + ' [Prix: ' + this.$prix + ']';
  }
}
