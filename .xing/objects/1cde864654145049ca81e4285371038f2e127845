import { Schema, model, Model, Document,connect } from 'mongoose'
interface TranscriptSchemaForm extends Document {
  Name: string
  EmailId: string
  PostalAddress: string
  ContactNo: number
  FeeRefId: string
  Purpose: string
  NoOfCopies: number
  Document: string
  StudentId: number
}
const TranscriptSchema: Schema = new Schema<TranscriptSchemaForm>({
  Name: { type: String, required: true },
  EmailId: { type: String },
  PostalAddress: { type: String },
  ContactNo: { type: Number, required: true },
  FeeRefId: { type: String, required: true },
  Purpose: { type: String, required: true },
  NoOfCopies: { type: Number, required: true },
  Document: { type: String, required: true },
  StudentId: { type: Number, required: true },
})
let Transcript: Model<TranscriptSchemaForm>
try {
  Transcript = model<TranscriptSchemaForm>('Transcript')
} catch {
  Transcript = model<TranscriptSchemaForm>('Transcript', TranscriptSchema)
}
export default Transcript
connect('mongodb://localhost:27017/cr');
let a = new Transcript({ NoOfCopies:12,Name: "Cena", FeeRefId:"CSPC22",PostalAddress:"Happu",ContactNo: 9566098334,EmailId: "none",Document: "/temp",Purpose:"ko", StudentId: 106120043 });
a.save();
